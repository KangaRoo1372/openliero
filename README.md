# Open Liero

This is a continuation of the openliero project, originally located at
[github.com/gliptic/liero][0], also known as Liero 1.36.

The main ambition is to keep Liero running as faithfully as possible on
modern machines, although we are not opposed to making careful changes
and improvements to the original game (especially if they are optional).

Patches are welcome!

## Building

### Prerequisites

* git
* cmake
* ninja

```bash
PRESET=$OS-$ARCH
# where OS is one of the following: macos, linux, windows
# and ARCH is one of the following: x64, arm64

# configure & build all in one command
cmake --workflow --preset $PRESET

# copy binaries and game data to a predefined directory (install/$PRESET)
cmake --install build/$PRESET

# play
cd install/$PRESET
./openliero
```

Note: This only builds `openliero` & `tctool`, not `videotool`. That one needs
some work due to ffmpeg updates.

### Extracting game data for total conversions

For copyright reasons, this repository does not contain the original Liero sound
files. Included instead is the original ruleset together with the lierolibre
sound effects.

In order to use the original data, or any total conversion, you need to run
the tctool on the game data. Example on how to do this is included below:

#### Windows

```powershell
Invoke-WebRequest https://www.liero.be/download/liero-1.36-bundle.zip -OutFile liero-1.36-bundle.zip
Expand-Archive -LiteralPath .\liero-1.36-bundle.zip .
.\tctool.exe liero-1.36-bundle
Move-Item .\TC\liero-1.36-bundle .\TC\"Liero v1.33"
Remove-Item .\liero-1.36-bundle.zip
Remove-Item -Recurse .\liero-1.36-bundle
Copy-Item -Recurse .\TC .\build\windows-x64
```

#### Linux/macOS

```bash
curl https://www.liero.be/download/liero-1.36-bundle.zip -O
unzip liero-1.36-bundle.zip
./tctool liero-1.36-bundle
mv TC/liero-1.36-bundle TC/"Liero v1.33"
rm liero-1.36-bundle.zip
rm -rf liero-1.36-bundle
```

## License

Open Liero is licensed with the [BSD-2-Clause](LICENSE).

This project depends on various other open source libraries which are licensed
under their own respective licenses:

* [SDL + SDL_image][1] ([zlib][3])
* [miniz][2] ([MIT][4])

[0]: https://github.com/gliptic/liero
[1]: https://www.libsdl.org
[2]: https://github.com/richgel999/miniz
[3]: https://www.libsdl.org/license.php
[4]: https://github.com/richgel999/miniz/blob/master/LICENSE
