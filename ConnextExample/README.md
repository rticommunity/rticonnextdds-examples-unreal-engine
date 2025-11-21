# ConnextExample: RTI Connext DDS with Unreal Engine 

This example was built with the following product versions:

* **Unreal Engine 5.6.1**

* **RTI Connext DDS Professional 7.6.0**

* **Microsoft Visual Studio 2022**

It would not be hard to use different versions of **Unreal Engine** or **RTI Connext DDS** or the platform (e.g., Linux).  See this section, [Porting ConnextExample](#porting-connextexample).

## Concept

You can create C++-based components with **Unreal Engine** to send or receive data using 
the **DDS** API.

1. Declare the datatypes (in IDL/XML format) that will be used by **DDS** *Topics* for sending or receiving data used by the **Unreal** application.

2. Using *rtiddsgen* from **RTI Connext DDS Professional**, generate the C++-98 (aka *Traditional C++*) code that define the datatypes used by the **Unreal** C++ code.

3. Create **Unreal** C++ components that receive data from **Unreal** *Blueprints* or other components, copy the data to a **DDS** data structure (declared in Step 1 and generated in Step 2), and then send the data with **DDS** using a *DataWriter*.

4. Create **Unreal** C++ components that receive data from **DDS** using a *DataReader*, and when data is received, copy the data into the **Unreal** variables that other components in an **Unreal** *Blueprint* can access.

Typically, you will need a different C++ component for each datatype that you want to send or receive with **DDS**.

## Example Description

This example was initially created with the **Unreal Project Browser --> Games --> Vehicle (Blueprint)**.  When running, the user can control/drive a car using the keyboard (arrow keys).  You have control over the throttle (up arrow), braking (down arrow), and steering (left/right arrows).

The example was modified to publish the state of the vehicle (Cartesian position and velocity, and attitude) to a **DDS** *Topic* "VehicleState".

### To Run

1.  Assuming that you have **Unreal Engine 5.6.1** (or compatible version) installed.  You should also install **RTI Connext DDS Professional 7.6.0**.  You can get a free download and license from [www.rti.com/get-connext](https://www.rti.com/get-connext).
    
    Install per instructions and make a note of your installation directory.  You will need create and set the value of an environment variable `NDDSHOME = <install dir>` in your host.

2.  Open [ConnextExample.uproject](./ConnextExample.uproject) in the **Unreal Engine** IDE (aka *Unreal Editor*).

    This may open a dialog window telling you that the *ConnextExample* module is "missing or built with a different engine version" and asks if you "would like to rebuild them now?".  Go ahead and click on *Yes*...when completed successfully, the *Unreal Editor* should open with the project loaded.
    
    Now Generate or Refresh the *Visual Studio Project* using **Tools --> Generate Visual Studio Project** or **Tools --> Refresh Visual Studio Project**

    IT's POSSIBLE THAT THIS DOESN'T WORK...the "rebuild" fails and the *Unreal Editor* doesn't open the project and doesn't even start.  In that case, you will need to regenerate the *Visual Studio* projects manually.  Run:

    `"C:\Program Files\Epic Games\UE_5.6\Engine\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.exe" -projectfiles -project="<installdir>\rticonnextdds-examples-unreal-engine\ConnextExample\ConnextExample.uproject" -game -engine`

    replacing `<installdir>` with the location of `rticonnextdds-examples-unreal-engine`.

3.  Compile the **Connext DDS** C++ components using **Microsoft Visual Studio**.  

    Open **Visual Studio 2022** (or compatible version), either using **Tools --> Open Visual Studio** or directly clicking on the file [ConnextExample.sln](./ConnextExample.sln).
    
    In **Visual Studio**, select the `Development Editor` configuration and Build the solution.

4.  Now open the `ConnextExample.uproject` in the *Unreal Editor* if you weren't able to before, and start the application in the *PIE* (Play-In-Editor) using the "Play" button with the green triangle icon.

5.  You can move the vehicle using the keyboard's up/down/left/right arrow keys (after clicking on the application window showing the vehicle).

6.  You can see that the vehicle's state as well as the command inputs (keyboard commands) are being published by **DDS** either by using the **RTI Connext** `rtiddsspy` utility from a command prompt or by starting **RTI Admin Console** and subscribing to the `VehicleState` and `InputCommand` topics in **Admin Console**.  

    The *User's Manual* for **RTI Admin Console** can be found [here](https://community.rti.com/static/documentation/connext-dds/current/doc/manuals/connext_dds_professional/tools/admin_console/index.html).


## Example Details

The following files were created and added to the project:

* [ConnextExample.sln](./ConnextExample.sln)

    Automatically generated when opening Visual Studio using the **Unreal Editor --> Tools --> Open Visual Studio**.

* [ConnextExample.Build.cs](./Source/ConnextExample/ConnextExample.Build.cs)

    You will need to modify this automatically generated file to add the paths to the **RTI Connext** include and library files as well as required compiler definitions to integrate **RTI Connext** with your **Unreal** application.  See [Visual Studio Project Modifications](#visual-studio-project-modifications).

* [UnrealBasicDDSTypes.idl](./Source/ConnextExample/UnrealBasicDDSTypes.idl)

    File used to define datatypes used by **DDS** *Topics* to send/receive data.

    You May customize this file to add your own datatypes or add/create new **.idl** files with additional datatype definitions.  Please refer to this documentation [Creating User Data Types with IDL](https://community.rti.com/static/documentation/connext-dds/current/doc/manuals/connext_dds_professional/users_manual/users_manual/Creating_User_Data_Types_with_IDL.htm#datatypes_842270378_306763).

    After defining your datatypes, you will use the **RTI Connext** code generator, [***rtiddsgen***](https://community.rti.com/static/documentation/connext-dds/current/doc/manuals/connext_dds_professional/code_generator/users_manual/code_generator/users_manual/UsersManual_Title.htm), to generate the source code that is required by *DDS* to use your datatype.

    To generate code for C++98 (*NOTE: cannot use C++11 due to RTTI conflict with **Unreal** C++*), you should invoke using (on a Windows host):

    `rtiddsgen -ppdisable -replace UnrealBasicDDSTypes.idl`

    Replace `UnrealBasicDDSTypes.idl` with your filename(s) if you want to use a different file.

    `rtiddsgen` should generate the following files which need to be added to the Visual Studio project to be compiled and linked with your component code:

    * UnrealBasicDDSTypes.h
    * UnrealBasicDDSTypesPlugin.h
    * UnrealBasicDDSTypesPlugin.cxx
    * UnrealBasicDDSTypesSupport.h
    * UnrealBasicDDSTypesSupport.cxx

    You should not edit these files and these files must be regenerated if you modify the associated "UnrealBasicDDSTypes.idl" file.

* [ConnextExampleQosProfiles.xml](./ConnextExampleQosProfiles.xml)

    This file contains the definitions of the **QoS Profiles** that can be used to configure the **DDS** Entities, *DomainParticipants*, "DataWriters*, and *DataReaders*, created and used by the C++ components.

    The application will load this file from the project's root directory at runtime.

    You can read more about defining QoS Profiles in XML [here](https://community.rti.com/static/documentation/connext-dds/current/doc/manuals/connext_dds_professional/users_manual/users_manual/XMLConfiguration.htm#xmlconfiguration_1275484337_216998).  If you are unfamiliar with **DDS** *Quality of Service* (QoS), you probably should look over this [chapter](https://community.rti.com/static/documentation/connext-dds/current/doc/manuals/connext_dds_professional/users_manual/users_manual/PartConfiguringQos.htm) of the [RTI Connext Core Libraries User's Manual](https://community.rti.com/static/documentation/connext-dds/current/doc/manuals/connext_dds_professional/users_manual/index.htm).

* [DomainParticipantComponent.h](./Source/ConnextExample/DomainParticipantComponent.h)
    
    [DomainParticipantComponent.cpp](./Source/ConnextExample/DomainParticipantComponent.cpp)

    These files define a C++ component derived from *UActorComponent* that you should add as a component into a *Blueprint*, see this [figure](#dds-component).  The *DomainParticipantComponent* will instantiate a **DDS** *DomainParticipant* when the *InitializeParticipant* method is invoked in the *Blueprint* (With the *ConnextExample* opened in the **Unreal Editor**, see *Content Drawer --> Connext Example --> All --> Content --> Vehicle Template --> Blueprints --> BP_VehicleAdvPawnBase*), see this [figure](#dds-init).

    The *InitializeParticipant* method takes a **DDS** *DomainId*, a *QosProfilePathName* of the format "<QosLibrary>::<QosProfile>", and the path name of a file contain the XML QoS Profile definitions used to create the *DomainParticipant*, *DataWriters* and *DataReaders*.

    An instance of this component will need to be added as an object reference to other components that use the DDS API to publish or subscribe to data (see examples below).  Each instance of this component will create a separate *DomainParticipant*.  Best practice is to use a single *DomainParticipant*, and thus a single instance of the *DomainParticipantComponent* for each **DDS** *Domain* (unique domain id) that an application uses to communicate with other applications.

* [AActor_DDSDataWriter.h](./Source/ConnextExample/AActor_DDSDataWriter.h)
    
    [AActor_DDSDataWriter.cpp](./Source/ConnextExample/AActor_DDSDataWriter.cpp)

    *AActor_DDSDataWriter* is an example of a component that can publish data using DDS.  It gets the data to publish from the *Owner* of the component in code and thus does not have a *pin* for data input from a Blueprint.
    
    The *AActor_DDSDataWriter* is added as a component into a Blueprint to send data about the state of the *AActor*-derived class that the Blueprint defines, see this [figure](#dds-component).  The "state" is the *AActor*'s position, velocity and attitude (aka rotation).

    The *AActor_DDSDataWriter* component must first be initialized (usually triggered by the event `BeginPlay`) with the name of the **DDS** *Topic* that it will publish and the name of the *QoS Profile* used to create the `DDSDataWriter`.  The *QoS Profile* name has the format `<QosLibraryName>::<QosProfileName>`.  See this [figure](#dds-init).

    There is no need to visually connect an *AActor_DDSDataWriter* component to an *AActor* object reference...the *AActor_DDSDataWriter* component assumes that the *AActor* is the *Owner* of the component and will send the state of the *Owner* when the `WriteActorState()` method is invoked.  Usually, you will insert a function node into the Blueprint that invokes the `WriteActorState()` method of an *AActor_DDSDataWriter* component based on some trigger (likely timer-based), see this [figure](#dds-write).


    When `UAActor_DDSDataWriter::WriteActorState()` is called, it gets the current state of the `Owner()` and copies the values into an `AActorType` structure, which is a **DDS** datatype defined in [UnrealBasicDDSTypes.idl](./Source/ConnextExample/UnrealBasicDDSTypes.idl).  Then it uses the `DDSDataWriter` created during initialization to send the value with **DDS**.

* [InputCommand_DDSComponent.h](./Source/ConnextExample/InputCommand_DDSComponent.h)
    
    [InputCommand_DDSComponent.cpp](./Source/ConnextExample/InputCommand_DDSComponent.cpp)

    *InputCommand_DDSComponent* is an example of a component that can both publish and subscribe to the same **DDS** *Topic*.  Usually, a single application will either send data for a *Topic* or receive data for a *Topic".  Instead of defining different component classes that either send or receive data, it's more efficient to just define a single component that can be used to do both...and then only use it to send or receive data in an application as needed.

    However, for the *ConnextExample* application, the *InputCommand_DDSComponent* is used to first send the control commands (throttle, steering, brake) via **DDS**, and then to receive the commands via **DDS** to drive the simulated vehicle.  The example was designed this way so that only a *single* application is needed to show you how to both publish and subscribe with **DDS** in **Unreal Engine**. 

    To use, the *InputCommand_DDSComponent* must first be added as a component into the Blueprint (see this [figure](#dds-component)) and then initialized to create either the *DataWriter* or *DataReader* (or both) for the desired **DDS** *Topic* (see [this figure](#dds-init)).  Usually, the initialization is triggered by the event `BeginPlay`.

    The data for the *InputCommand_DDSComponent* either come into node invoking the `WriteInputCommand()` method for publishing or come out of the node invoking `ReadInputCommand()` for subscribing.  The data pins (float variables for throttle, steering, brake) are exposed by the function nodes to connect to corresponding variables in the Blueprint (either coming from an *InputAction* component for publishing or going to components that set the values for throttle, steering and brake to drive the *Vehicle Movement Component*), see [this figure](#dds-publish-subscribe).


## Using the DDS components in a Blueprint

<figure id="dds-component">
  <img src="./BlueprintComponent.png" alt="Add DDS components to a Blueprint">
  <figcaption>Use the "+Add" in the Components view to add the DDS components to a Blueprint</figcaption>
</figure>

User-defined **DDS** C++ Components should be added via the *Components* view.  Although you may instantiate as many AActor_DDSDataWriter and InputCommand_DDSComponent objects as needed in an application (perhaps for controlling multiple vehicles), usually you only need a single DomainParticipantComponent.

<figure id="dds-init">
  <img src="./InitializationSnapshot.png" alt="DDS components initialized in a Blueprint">
  <figcaption>Initialization of DDS components in a Blueprint</figcaption>
</figure>

All of the User-defined **DDS** C++ Components should be initialized when triggered by Event *BeginPlay*.

<figure id="dds-write">
  <img src="./AActorDDSWrite.png" alt="Calling UAActor_DDSDataWriter::WriteActorState()">
  <figcaption>UAActor_DDSDataWriter::WriteActorState() is hooked up to an Event Tick in the Blueprint</figcaption>
</figure>

Invoking the `WriteActorState()` function of an instance of the `AActor_DDSDataWriter` component will send the state of the Actor represented by the Blueprint (in this case the Vehicle) with **DDS**.

<figure id="dds-publish-subscribe">
  <img src="./PublishSubscribeSnapshot.png" alt="DDS components publishing and subscribing a Blueprint">
  <figcaption>Using DDS components to send and receive data in a Blueprint</figcaption>
</figure>

As a contrived example, the direct connection between the *InputAction* components and the *Set XXX Input* nodes for throttle, steering and brake is broken.  Usually, when the user hits the arrow keys, the corresponding *InputAction* will send a value to a *Set XXX Input* node which invokes a method on a *Vehicle Movement Component* to control the vehicle.

In the *ConnextExample*, the *InputAction* components are wired to a *Write Input Command* node that take the commanded values for throttle, steering and brake and publishes them as a **DDS** *Topic*.  Then, in the same Blueprint, the values are received via *DDS* by a *Read Input Command* node whose output is fed to the *Set XXX Input* nodes, subsequently controlling the *Vehicle Movement Component*.  While unorthodox, this design shows you how to send data out of and receive data into an **Unreal** application with a single Blueprint.

## Visual Studio Project Modifications

To build and link **RTI Connext** with your own **Unreal** application, you will need to add paths to the **DDS** include files, the required binary libraries for linking as well as some compiler macros (#defines).

You will need to add the following code snippet to your own *.Build.cs* file, for example [ConnextExample.Build.cs](./Source/ConnextExample/ConnextExample.Build.cs).

The following code assume that the environment variable *NDDSHOME* has been set to the path of your **RTI Connext** installation directory when you build the application.

To use the static **RTI Connext** libraries, add the following code:

```    
    public class ConnextExample : ModuleRules
    {
        public ConnextExample(ReadOnlyTargetRules Target) : base(Target)
        {
            <...>

            string nddshome = Environment.GetEnvironmentVariable("NDDSHOME");
            PublicIncludePaths.Add(Path.Combine(nddshome, "include"));
            PublicIncludePaths.Add(Path.Combine(nddshome, "include/ndds"));

            if (Target.Platform == UnrealTargetPlatform.Win64)
            {
                PublicDefinitions.Add("WIN32");
                PublicDefinitions.Add("RTI_STATIC");
                PublicDefinitions.Add("WIN32_LEAN_AND_MEAN");
                PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Win64VS2017/nddscppz.lib"));
                PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Win64VS2017/nddscz.lib"));
                PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Win64VS2017/nddscorez.lib"));
            }
            <...>
```

To use dynamically-linked libraries, insert the following lines instead:

```
            if (Target.Platform == UnrealTargetPlatform.Win64)
            {           {
                PublicDefinitions.Add("WIN32");
                PublicDefinitions.Add("NDDS_DLL_VARIABLE");
                PublicDefinitions.Add("WIN32_LEAN_AND_MEAN");
                PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Win64VS2017/nddscpp.lib"));
                PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Win64VS2017/nddsc.lib"));
                PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Win64VS2017/nddscore.lib"));
                
                RuntimeDependencies.Add(Path.Combine(nddshome, "lib/x64Win64VS2017/nddscpp.dll"));
                RuntimeDependencies.Add(Path.Combine(nddshome, "lib/x64Win64VS2017/nddsc.dll"));
                RuntimeDependencies.Add(Path.Combine(nddshome, "lib/x64Win64VS2017/nddscore.dll"));
                
                //Needed since generated type support code uses exceptions
                bEnableExceptions = true;
            }
```

## Porting ConnextExample

* Changing the version of **RTI Connext DDS**

    If you are using a different version of **RTI Connext DDS Professional**, then you should regenerate the C++ source and header files that support the DDS datatypes used by the project as explained in the [Example Details](#example-details) for the file  [UnrealBasicDDSTypes.idl](./Source/ConnextExample/UnrealBasicDDSTypes.idl).
    
    You will need to invoke
    
    `rtiddsgen -ppdisable -replace UnrealBasicDDSTypes.idl`

    using the *rtiddsgen* distributed with your version of **RTI Connext DDS**.  *rtiddsgen* is usually located in *<ConnextInstallDir>/bin/rtiddsgen*.

* Changing the platform to Linux

    The code of the **DDS**-related components such as *UDomainParticipantComponent*, *UAActor_DDSDataWriter* and *UInputCommand_DDSComponent*
are platform independent and should work both in Windows and Linux.

    In the file, [ConnextExample.Build.cs](./Source/ConnextExample/ConnextExample.Build.cs), there is already code to add the libraries and compiler macros required to build on Linux.
    
    For example, for linking statically, 

            PrivateDefinitions.Add("RTI_LINUX");
            PrivateDefinitions.Add("RTI_UNIX");
            PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Linux5Unreal5.2clang15/nddscppz.a"));
            PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Linux5Unreal5.2clang15/nddscz.a"));
            PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Linux5Unreal5.2clang15/nddscorez.a"));

    For linking dynamically,

            PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Linux5Unreal5.2clang15/nddscpp.so"));
            PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Linux5Unreal5.2clang15/nddsc.so"));
            PublicAdditionalLibraries.Add(Path.Combine(nddshome, "lib/x64Linux5Unreal5.2clang15/nddscore.so"));
            RuntimeDependencies.Add(Path.Combine(nddshome, "lib/x64Linux5Unreal5.2clang15/nddscpp.so"));
            RuntimeDependencies.Add(Path.Combine(nddshome, "lib/x64Linux5Unreal5.2clang15/nddsc.so"));
            RuntimeDependencies.Add(Path.Combine(nddshome, "lib/x64Linux5Unreal5.2clang15/nddscore.so"));

            // Needed since generated type support code uses exceptions
            bEnableExceptions = true; 

    You will have to make sure that your *Unreal Engine* project is enabled to build Linux applications (cross-compiled from Windows or natively on Linux).  Please consult the *Unreal Engine* documentation on how to do this.  The example project, *ConnextExample*, is only setup to compile for Windows.

    **Note:  This code and project has not been tested and verified to build for Linux.  While the code should compile, there may be issues during linking that
      can be resolved by adding the compiler/linker flags "-stdlib=libc++",  "-fno-rtti", and "-m64".  You may also need to add the following libraries "-ldl -lm -lpthread -lrt".**

* Changing the version of **Unreal Engine**

    If you are using a different version of **Unreal Engine**, you should consult **Unreal** documentation on how to update your project to work with a version of **Unreal Engine** newer than 5.6.1.  To port to an older version of **Unreal Engine**, you should just manually create a new project with your version's *Editor* and then add the C++ source and header files, the ".xml" QoS file to the project.  And then add the required compiler macros, include paths, and libraries for **RTI Connext DDS** to the file "*\<project\>.Build.cs*" of your project.