> Plan 9 Editors: Sam & Acme

This is a fork of the Sam and Acme editors, derived from the [Plan 9 from User Space (aka plan9port)](https://9fans.github.io/plan9port/) project (itself a port of many Plan 9 utilities to Unix).

This version tacks on a few extra keybindings and some functionality to allow a more keyboard-driven editing experience. Given both editors' emphasis on mouse use, this is perhaps somewhat heretical...

## Changes

- The X11 and MacOS implementations of `devdraw` now support further combination keybindings such as `Ctrl + Shift + Key`.

- The default keybindings for **both** Acme and Sam now include:

| Key combination | Function | Comment(s) |
| --- | --- | --- |
| `Ctrl + c` | Snarf (copy) | Use `Ctrl + Shift + c` for sending `^C` (0x03). |
| `Ctrl + x` | Cut | Use `Ctrl + Shift + x` for sending `^X` (0x18). |
| `Ctrl + v` | Paste | Use `Ctrl + Shift + v` for sending `^V` (0x16). |
| `Shift + Left` | Extend selection left by one character |  |
| `Shift + Right` | Extend selection right by one character |  |
| `Ctrl + Shift + Left` | Extend selection left to start of line | |
| `Ctrl + Shift + Right` | Extend selection right to end of line | |
| `Up` | Move cursor up one line | Moves the cursor to the same character position on the previous line, or the end of the previous line if it is shorter. Tabs are treated as a single character! This works best with fixed-width (`monospace`) fonts. Use `PageUp` for scrolling. |
| `Down` | Move cursor down one line | Moves the cursor to the same character position on the next line, or the end of the next line if it is shorter. Tabs are treated as a single character! This works best with fixed-width (`monospace`) fonts. Use `PageDown` for scrolling. |
| `Shift + Up` | Extend selection up one line | Extends the selection to the same character position on the previous line, or the end of the previous line if it is shorter. Tabs are treated as a single character! This works best with fixed-width (`monospace`) fonts. |
| `Shift + Down` | Extend selection down one line | Extends the selection to the same character position on the next line, or the end of the next line if it is shorter. Tabs are treated as a single character! This works best with fixed-width (`monospace`) fonts. |
| `Delete` | Delete character to the right of the cursor | Also deletes a selection. Use `Shift + Delete` for sending `^?` (0x7F). |

- Additionally, the following shortcuts have been added for **Acme only**:

| Key combination | Function | Comment(s) |
| --- | --- | --- |
| `Ctrl + z` | Undo | Use `Ctrl + Shift + z` for sending `^Z` (0x1A). |
| `Ctrl + y` | Redo | Use `Ctrl + Shift + y` for sending `^Y` (0x19). |
| `Ctrl + s` | Put (save) | Use `Ctrl + Shift + s` for sending `^S` (0x13). |
| `Ctrl + Return` | Execute selected text as a command | Same as mouse button 2 click. |
| `Ctrl + Shift + Return` | Locate or acquire the file/string/etc currently selected | Same as mouse button 3 click. |

- Finally alongside the new keybindings there are some Sam specific changes: window focus follows the mouse (rather than by clicking), and the mouse scroll-wheel can be used to scroll.

## Installation

The main requirement is [9fans/plan9port](https://github.com/9fans/plan9port.git). Usually this is installed to `/usr/local/plan9`:

```sh
git clone https://github.com/9fans/plan9port.git /usr/local/plan9
cd /usr/local/plan9
./INSTALL
export PLAN9=/usr/local/plan9
export PATH=$PATH:$PLAN9/bin
```

With the plan9port utilities accessible, the editors can be built using `mk`:

```sh
git clone https://github.com/lewis-weinberger/9ed.git
cd 9ed
mk install
```

This will create four executables: `sam`, `samterm`, `acme` and `devdraw`, installed by default at `$PLAN9/bin/`. To install the executables at a custom location, set the `BIN` environment variable (e.g. `mk install BIN=/usr/local/bin`). If installed at a custom location, make sure to set the `PATH` environment variable (as above) such that these new versions are found before the plan9port versions.

**CAUTION**: this is a personal fork with changes made based on my preferences, and only tested by me. Some of the changes may introduce new bugs and cause the editors to crash unexpectedly. Use at your own peril!

## Usage

See [acme(1)](https://9fans.github.io/plan9port/man/man1/acme.html) or [sam(1)](https://9fans.github.io/plan9port/man/man1/sam.html), as well as the original papers by Rob Pike describing the editors:

- [Acme: A User Interface for Programmers](https://9p.io/sys/doc/acme/acme.pdf)
- [The text editor Sam](https://9p.io/sys/doc/sam/sam.pdf)

There are helper scripts [a](./bin/a) and [s](./bin/s) which can be used to configure some of the runtime settings.
