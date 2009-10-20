     Silkworm v4.12a: A companion
     program for Worms Armageddon
          Copyright © 2002
   by Deadcode <qubit@inorbit.com>

     ==========================
     |      Instructions      |
     ==========================

Unzip Silkworm.dll and Silkworm_patch.exe to your Worms Armageddon directory.
Execute Silkworm_patch. It will automatically make a backup before patching.
Note that it patches DXMfc.dll, not WA.EXE itself, in order to work on both the
U.S. and European versions of the game.

Note: Silkworm only works on version 3.0 of Worms Armageddon. If you are using
version 1.0, you must install the Team17 patch which can be downloaded here:
  http://www.team17.com/download/?WAPatch.exe+WAPatch.exe
If the CD check fails after installing this patch, you must find a copy of the
USA WA.EXE and replace your current one with it.

You can check the version by right-clicking on WA.EXE (with the "radioactive"
icon) in your Worms Armageddon directory and clicking Properties; then look
under the Version tab.

     -= Extra Compatibility =-

There is a checkbox labelled "Work in Windows 2000 / XP" which will allow Worms
Armageddon to run in those operating systems. It also gets rid of the bug where
pressing the side buttons or wheel on your mouse would lock out keyboard input;
for this reason, it would be a good idea to enable the option even if you are
using Windows 9x.

If you are using the European version of Worms Armageddon, you will need to find
a copy of the USA WA.EXE and replace your current one with it. Otherwise it will
still not work under Windows 2000 or XP.

  -= Anti-cheating functionality =-

While in a game, type "/nosilk" in the chat box to disable all the cheats that
were available in Silkworm v3.50 and below, for anyone present. They will have
to restart Worms to restore the cheats; in the meantime, you'll be able to play
a fair game against them (unless they quit in defiance). Note: "/nosilk" does
not have any effect on the features of Silkworm v3.7 and above, and two /nosilk
commands will NOT cancel each other out.

You may also disable whisper/anon spying for anyone present in a game by typing
"/nospy". To combine /nosilk and /nospy into one command, type "/nocheat". Note
that this doesn't change the basic way whispers work; it only disables the
in-game spying mechanism (which could have been enabled either by the whisper
patch or by a password sent to oneself).

Both of these commands can be made automatic by checking them in the Silkworm
dialog box that pops up when you start Worms.

     -= Custom Resolutions =-

Silkworm also allows you to play in custom resolutions, as long as the vertical
resolution is 768. On a 4:3 monitor these modes will be letterboxed, so it's
probably impractical unless you have a rather large monitor. I have a 21"
monitor and I use 1280x768; this enables me to see more of the landscape at one
time. I created a 1280x768 mode using PowerStrip, which is obtainable at
http://www.entechtaiwan.com/ps.htm. Make sure you reboot after creating a custom
video mode; otherwise it will not be visible to Worms.

   -= Custom hosting options =-

Silkworm allows you to host games with weapons previously available only through
crates; this includes the Super Weapons, Select Worm, and Crate Spy. These
weapons appear in the same dialog as all the other ones, and apply both to
offline and online games. This functionality is enabled through the checkbox
"Enable custom hosting options" in the opening Silkworm dialog box.

There wasn't quite enough room for all the extra weapons. So, I implemented two
mini-pages of weapons. To flip between the pages, hold down Shift and click the
ammo setting for one of the extra weapons. Two mini-pages aren't quite enough
for all of the 18 extra weapons, so page 1 differs depending on whether you
cycle using Shift-LeftClick of Shift-RightClick.

You can also enable "global macros". These are enabled for everyone in the game,
locally and remotely. Currently, there is one global macro available; it enables
automatic parachute selection (at the beginning of every turn and after each
use) and a set of dedicated weapon hotkeys on the numeric keypad. To uncover
this option, hold down Shift and click the mouse on the teleporter button
(manual/automatic placement) in the main hosting screen. This will toggle the
button between the two functions. Clicking without holding down Shift will
toggle the currently visible option.

Weapon hotkey layout on the numeric keypad:

[7:Blowtorch ]  [8:Drill     ]  [9:Girder    ]
[4:Firepunch ]  [5:Dragonball]  [6:Prod      ]
[1:Rope      ]  [2:Bungee    ]  [3:Parachute ]
[0:Teleport                  ]  [.:SelectWorm]

All of the custom hosting options are saved into scheme files. Note that the
extended scheme files produced by Silkworm are of a non-standard size, and if
"Enable custom hosting abilities" is NOT checked, you will not be able to open
them. Also note that if you join somebody else's hosted game, and they are using
Silkworm with custom weapon options, you will not see those options until the
game starts; the extra weapons will appear to be zeroed out.

NOTE: Custom hosting has a bug, which will sometimes cause the game to crash
when entering map edit mode. For some people it will never happen. I've had it
happen a few times under XP. But I don't think it would be worthwhile for me to
track down this bug, since I will be working for T17 very soon and will be
reimplementing what I added in custom hosting (and it will be much easier to do
at the source code level -- doing it as a patch was pretty hairy).

      -= Local Ropeknock =-

In this version of Silkworm, there is a simple option included that can force
rope knocking to be enabled. This option is not meant to be used on wormNet,
and if it is used in a TCP/IP or IPX network game, all sides must have it
enabled, or a desync will occur.

       -= Miscellaneous =-

Once you have chosen your desired settings, you may use a commandline option of
"/nointrosilk" to skip the opening dialog. To do this, get the properties on
your Worms Armageddon shortcut, and add " /nointrosilk" to the end of the
Target.

===============
Version history
===============

Silkworm v4.12a - 17 Mar 2002
 * /nointrosilk parameter now works under Windows 95/98/ME

Silkworm v4.12 - 16 Mar 2002
 * Protects against people crashing a game (before it starts) by joining with a
   hacked client (like the one "Name" uses). Note, this may not protect against
   all possible methods
 * Renamed a couple checkboxes to be more descriptive

Silkworm v4.11 - 19 Feb 2002
 * Hosts can now boot people from a game (before it starts) even if they have
   hacked their client to ignore boot messages (like "Name" did)
 * New command line option "/nointrosilk" to skip opening Silkworm dialog

Silkworm v4.10a - 03 Jan 2002
 * Bugfix: Manual worm placement did not work if global macros were enabled.

Silkworm v4.10 - 03 Jan 2002
 * Added a "global macro" option which can be enabled in a game you are hosting.
   When enabled, it automates parachute selection and provides a set of Team17
   weapon hotkeys on the numeric keypad. The availability of this option is
   controlled by the same "Enable custom hosting abilities" checkbox.
 * Hosting with super-weapons should be a bit more reliable now, if it caused
   any desyncs before
 * Fixed a bug in the rewritten checksumming routine, in which the hourglass
   cursor didn't go away upon completion
 * Added an option to skip fading between full-screen dialogs

Silkworm v4.01b - 25 Dec 2001
 * Got rid of checksum errors once and for all (the last straw preventing Worms
   Armageddon from working under Windows XP for some people).

Silkworm v4.01a - 24 Dec 2001
 * Fixed /nospy to work on the old version of the whisper patch (which showed
   you what people were whispering, but not who was saying it)
 * Fixed a bug where Silkworm-appended schemes could not be loaded if you
   were using the 3.1 MB version of WA.EXE
 * If you're playing with a Silkworm-appended scheme, it goes ahead and lets you
   use the air and napalm strikes in a cavern level. It already let you use the
   other ones, so I decided symmetry would be best.

Silkworm v4.00 - 20 Dec 2001
 * Added buttons to the weapons options screen for all the weapons that were
   previously available only through crates. These extra settings are saved
   appended onto a scheme file, and work for offline and online games. Since
   this is a rather sweeping change, there are likely to be bugs. So, I made
   this extension optional; it is enabled through a checkbox in the opening
   dialog.
 * Integrated the local ropeknock patch
 * Added a picture of a silkworm to the opening dialog. :)

Silkworm v3.76 - 11 Dec 2001
 * Yay! I got Worms Armageddon to work in Windows 2000. This fix almost
   certainly will work under Windows XP as well, though I cannot test it
   myself. It is now enabled through a checkbox in the Silkworm dialog box!

Silkworm v3.75 - 03 Dec 2001
 * The "/nosilk" command may be more stable now. If it caused a crash for
   anyone, chances are, it probably won't anymore.
 * Added a "/nospy" command which disables whisper/anon spying for anyone
   present in the current game. Also, "/nocheat" is a shortcut for /nospy and
   /nosilk combined.
 * Added the ability to use resolutions wider than 1024x768, up to 1920x768.
   PowerStrip or a similar program is required to create the custom mode.
 * There a few Silkworm settings available now when you start Worms; these
   settings are saved into an INI file.
 * Changed the way the patch works. It should now work on the European version
   of the game.

Silkworm v3.74 - 11 Nov 2001
 * Added an anti-#me-forging patch. If someone tries to forge a #me message in
   the WormNet lobby, you will be able to see who did it.

Silkworm v3.73 - 08 Nov 2001
 * Fixed a bug that caused /nosilk to crash the game if the video resolution
   wasn't 1024x768.

Silkworm v3.72 - 06 Nov 2001
  Initial release. A fresh start from previous versions of Silkworm, which gave
  unfair powers to those who possessed it. Version 3.72 does only one thing: it
  allows the user to remotely disable all the Silkworm cheats for anybody in
  the current game, using a /nosilk command.

Silkworm v3.50
  The last version I unwisely gave away. Please do NOT ask me for it; I'm not
  giving it to any more people. It had the following cheats:
  * Automatic reselection of parachute after each use.
  * Automatic use of the fastwalk glitch by holding down a key (makes a worm
    walk approximately 50% faster).
  * The appearance of avoiding fall damage through rapidly cycling the
    parachute. This works even if the parachute isn't selected; the currently
    selected weapon is remembered and reselected when you land on solid ground.
  * Ability to automatically trigger a preselected weapon; if that weapon is
    targetted, you can preselect a target. This automatic triggering can be done
    much faster than would be humanly possible.
  * Hotkeys for the commonly used T17 weapons.
  * Automatic rope shadow, triggered by a key.
  * Ability to point at a target and automatically aim and fire at it with a
    bazooka, homing missile, mortar, sheep launcher, grenade, cluster bomb,
    banana, any kind of gun or longbow, super banana, holy hand grenade, or
    petrol bomb.
  * Ability to place a girder anywhere on the map, regardless of whether it
    intersects with existing land, crates/barrels or even worms.
  * Ability to release an indefinate number of cows while holding only one cow;
    between each cow one can walk to different places.
  * Ability to pause the turn timer and continue one's turn indefinately, and
    resume the timer at will. Sudden death can also be triggered at will (on the
    following turn).
  * Ability to cause any team to surrender. This can only be done during one's
    own turn; therefore it is easy to tell who caused the surrender.

==========
Background
==========

I originally wanted to create a "companion program" for Worms Armageddon that
would automate reselection of the parachute for T17-scheme games. It started out
as a simple macro program, but evolved to much more than that. I implemented
several features for the fun and the challenge; many of these features happened
to be rather powerful cheats, though I meant to use them only for fun.

Along the way I gave my program to some friends, making them promise not to
distribute it to anyone at all. A couple of them broke that promise, and now
people have spread it all around.

The problem is, some of the cheats, such as auto-aiming of grenades and
bazookas, cannot be detected. If used properly, it looks like the person is
aiming manually, but with deadly accuracy.

As a solution to this problem, I have written an "anti-program" that will
remotely and locally disable all previous versions of Silkworm. Using the
disabler affects ALL people in the game, even the one using it; nobody will be
able to use the cheats after it is activated.

However, my vision of extending Worms Armageddon beyond its original design is
still quite alive. My focus is now entirely different from what it was. Instead
of creating "cheats" which, in terms of game play, give a distinct advantage to
those who use them, I am working on extending Worms for everyone.