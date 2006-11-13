Welcome to the dvdrental project!

This is the folder structure of the project:

/bin:     Latest ready-to-use binaries for different platforms.
/deploy:  Deployment scripts for different platforms.
/doc:     Documentation of any kind, in the form of UML diagrams, CHM or PDF files.
/ext:     External tools used in the project (libraries, scripts, etc).
/make:    Makefiles, Ant build files or other scripts used to build the source code, in different platforms.
/project: Project files for different IDEs (Xcode, Visual Studio, etc).
/src:     The source code itself.

Notes:

The deployment scripts in the /deploy subfolder use the build scripts in the /make subfolder, but provide more than just building the source code:

1) They have the ability to create final deliverables, for example ZIP or MSI files for Windows, DMG files for the Mac or tar.gz files for Linux.
2) They test the source code, launching the unit tests automatically.
3) They are usually scheduled for daily execution.
