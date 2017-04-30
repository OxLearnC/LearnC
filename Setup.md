# Setting up a development environment

A development environment for C++ consists of two things: a compiler and an editor. These are usually installed separately and the installation process depends on the operating system.
I recommend using CodeLite as an editor, since it comes with a compiler making installation easier, but feel free to use your favorite text editor (at your own risk!)

## Installing CodeLite

You can get CodeLite for free at [http://downloads.codelite.org](http://downloads.codelite.org) - you can choose either the Weekly or the Stable build,
which should make no difference at all (unless you're running a 32 bit system, in which case you may have to use Stable).

### Installing CodeLite on Windows

Download and run the installer (either Weekly or Stable). When CodeLite has finished installing, run it to complete the configuration process.
CodeLite will let you skip this step if you'd like, but you shouldn't do that!

![](/images/SkipSetup.png)

Then you will see a list of plugins that you can choose not to install. We won't be using most of them, but they do no harm so just leave them all
checked.

![](/images/Plugins.png)

Now here comes the important part. CodeLite is essentially just a text editor - it can edit C++ code but it can't compile and run it, so it will ask
you whether you have a C++ compiler already installed. Since you probably don't (and installing a C++ compiler on Windows is usually a messy process),
you should click on Install and then select the MinGW-TDM 5.1/32bit compiler (select the 32 bit compiler even if you're using a 64 bit system!)

![](/images/CompilerSetup.png)

The installation program will take you to the download page of the TDM compiler. When the download is finished, run the TDM installer and select
the option Create to install the compiler (again, make sure to select the 32 bit version of the compiler).

![](/images/CompilerInstall.png)

You can just click Next through all the subsequent screens, since the default options are just what we want. After TDM has finished installing,
we can go back to CodeLite. This time click on Scan and a list of available compilers should appear (in your case, the only option will be TDM-GCC),
so just select the right one and go ahead.

![](/images/CompilerList.png)

Finally, you get the option to choose a colour scheme for the editor and whether to use tabs or spaces for indentation. These are completely up
to you!

![](/images/NoWorkspace.png)

After all this hard work, you should see a welcome screen, and a series of options for dealing with workspaces. A workspace is simply a set of projects
that use the same configuration. Let's just create a new one by clicking on New Workspace and selecting our favourite language (which is, of course, C++!)
The name and path are up to you, this merely tells CodeLite where to put all your files, and where the resulting programs will be saved.

After creating the workspace, you should be faced with an even more boring screen

![](/images/NoProject.png)

This is because we haven't created a project yet. To create one, just click on File/New/New Project and select the option Console/Simple Executable (g++)

![](/images/CreateProject.png)

Again, you get to choose the name and the project path. Finally, you get to pick from a list of possible tools that will be used to compile this project.
It should be the only choice, but make sure that the selected compiler is MinGW (TDM-GCC-32) and the build system is set to Default.

![](/images/NewProject.png)

At last, we finally have some C++ code on the screen! To make sure everything works, click on Build/Run (or, if you like shortcuts, just press Ctrl+F5).
This tells CodeLite to compile your program (i.e. generate a .exe file) from the sources, then run it. You should see the program running in a terminal
window.

![](/images/EndResult.png)

The generated program will be located in the Debug folder wherever you chose to save your project, and you can also run it by double-clicking on it.
You can even send it to other people, and they can run it without installing anything, as long as they are using the same operating system as you!

![](/images/ProgramFile.png)


### Installing CodeLite on Linux

On Linux, the installation process is equally simple: just download the package for your Linux version from the download page and use the package
manager to install it. You can also install it from the repositories via `apt-get` or similar, but it may be out of date (Ubuntu 16.04 only has CodeLite 9.1),
so it's better to download the installer. Alternatively, you can add the CodeLite repositories to your package manager by following the instructions [here](http://codelite.org/LiteEditor/Repositories),
but I don't recommend this unless you know what you're doing.

After it's done, you'll have to go through the same configuration steps as in Windows. However, you won't be able to
install a C++ compiler in the same way, you'll need to use your distro's repositories. You'll want to install packages `gcc` and `g++`.
Depending on what distribution and version you're using, you will have access to a different version of the compiler. Ideally, you should
install `gcc-5.1` and `g++-5.1` (or later). If these are not available, aim for `gcc-4.9` and `g++-4.9`, or the closest you can get.

Once you've installed a compiler, you can proceed to configure CodeLite just as in the Windows version.

### Installing CodeLite on Mac

If you have a Mac, you don't need to install CodeLite, just download the Mac version of CodeLite and unzip it, then go through the same configuration
steps as before.

If CodeLite can't find a C++ compiler in your system, you'll also need to install XCode, which you can find in the App Store for free. You can also
use XCode as a C++ editor instead of CodeLite!

## Alternative editors

If you can't install CodeLite, don't like it or are feeling curious, other good free editors you can use are:

* [Eclipse C++](http://www.eclipse.org/downloads/packages/eclipse-ide-cc-developers/neon3) (Windows, Linux, Mac, comes without a compiler, kind of slow)

* [Visual Studio Community](https://www.visualstudio.com/downloads/) (Windows only, comes with a compiler, lots of features, huge download)

* [XCode](https://itunes.apple.com/gb/app/xcode/id497799835) (Mac only, comes with a compiler)

* [NetBeans](https://netbeans.org/features/cpp/) (very similar to Eclipse) 

* [Code::Blocks](http://www.codeblocks.org/downloads/26) (Windows, Linux, Mac, the Mac version is very outdated, comes with a compiler, very nice for Windows/Linux users)
