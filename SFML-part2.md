# Installing SFML on Windows, part 2

Some people are having problems with SMFL on Windows. This is because we are using TDM-GCC 5.1.0 but SFML uses TDM-GCC version 4.8.1. 
Unfortunately, TDM-GCC 4.8.1 is no longer available, so we must switch to a different compiler.

We will use MinGW-w64, which you can find [here](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/installer/mingw-w64-install.exe/download).

When the download is over, run the installer. Make sure you select the following options:

* Version: 4.9.2
* Architecture: i686
* Exception: dwarf

When the installation is done, download the right version of SFML from [the downloads page](https://www.sfml-dev.org/download/sfml/2.2/). This time,
make sure to download the version marked as GCC 4.9.2 MinGW (DW2) - 32 bit, and unzip the resulting folder wherever you want (I use C:/SFML-2.2, but you
should use whatever path you installed SFML to before).

Open CodeLite and go to Settings -> Build Settings. On the Compilers tab, click the green plus sign and navigate to the folder where you installed MinGW-w64,
and click OK.
By default, this is

* C:/Program Files (x86)/mingw-w64/i686-4.9.2-posix-dwarf-rt_v4-rev4/mingw32/bin

CodeLite should have detected the settings for this compiler.

To configure your project to use this compiler, right click on the project, then click Settings. On the General tab, select the compiler we just installed from
the drop-down menu.

If you copied the new SFML to the same folder where you put the previous version, no further configuration is necessary - otherwise remember to update the
`include` and `lib` paths.

Lastly, when you try to run a program, you will see an error message about a missing `libgcc_s_dw2-1.dll` - don't panic! Simply go to

* C:/Program Files (x86)/mingw-w64/i686-4.9.2-posix-dwarf-rt_v4-rev4/mingw32/bin

then copy the dll files in that folder to the folder where your program is being compiled. Everything should now work!
