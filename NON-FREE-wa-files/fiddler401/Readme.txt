Fiddler 4.01 Readme - by Edward Webb - 24th September 2006
==========================================================

a. Changelog

1. Introduction
2. Setup
	a. Important info
	b. How to setup Fiddler
3. The Fiddler
	a. How to use
	b. Caveats
4. Future
5. Credits


Changes since last version
==========================

Fiddler 4.01 (unofficial version)

o Now works with Windows XP.
o Changed Fiddler's 'Go!' button to look for '30.exe' instead of 'WA.exe',
  for those who have a more recent version of Worms Armageddon.
o Removed the right hand sidebar with dead web links
o Updated Fudge Boy's email address, link to the Wormsmart website
o Updated the Amazon gift certificate link

Fiddler 4.0
o Released on the 3rd April 2000, see Fiddler.rtf for more details.


Introduction
============

Welcome to The Fiddler! In this document, you will be able to find out about
what Fiddler is, how to set it up, and future plans for the program.

The Fiddler is a game editor for Worms Armageddon, created in 1999 by James
Heather (aka Fudge Boy), created because of the lack of options in the game.
Eventually, it not only was able to change a whole variety of options, but
could even create brand new weapons.

Fiddler was more successful than anyone could have dreamed about, and a small
community rose from the exchange of Fiddler files and new weapons through the
WormsMart website. Though development of the program stopped in April 2000, as
James was completing his Ph.D at the time, the site continued to flourish for
well over a year after its release.

There are still fans of the program in 2006, 6 years since Fiddler was last
developed, so this release is designed to make installing Fiddler as simple and
straightforward as possible.

Good luck with using Fiddler and making weapons, and you can also send them in
to the WormsMart website, reopening soon, by e-mailing edwardwebb@btinternet.com ,
and they will be published on the website.


Important info
==============

The Fiddler was released in 2000, before Windows XP was released, the Sold Out
and Trymedia versions being made, and Deadcode developing the later versions of
Worms Armageddon.

When XP was released, a bug was discovered in Fiddler which stopped it from
working on the new OS. In addition, it was found that Worms Armageddon itself
didn't work on XP either, until Deadcode developed a program called Silkworm
(the non-cheat version) which fixed the problem.

Because Fiddler patches the game's memory, it has to know where it is going to
patch, which meant the program had to be updated for each new version. The last
version it supported was version 3.0.0.0 (shortened to 3.0), so you will need a
copy of version 3.0 for Fiddler to work.

Fiddler doesn't work with the Sold Out and Trymedia versions. If you have either
of these, then you can get an original copy from Team17, at their online store:

https://secure.team17.com/

You can get Worms Armageddon together with its predecessor Worms2 for £6 + P&P.

In this version of Fiddler, instead of looking for a 'WA.exe' when you press the
'Go!', it will attempt to open '30.exe'. This is so that both WA 3.0 and the
later versions can co-exist in the same place.


How to setup Fiddler
====================

You will need the following:

o Fiddler 4.01
o Fiddler.reg
o Silkworm 4.12a
o Worms Armageddon 3.0

The first three are included in the zip file, 

To start, copy 'The Fiddler' directory to your Worms Armageddon directory. If
you already have the Fiddler, you can just copy the new Fiddler.exe on top of
the existing one.

Next, Fiddler needs to know where Worms Armageddon is installed, using
Fiddler.reg. If WA is installed in "c:\team17\Worms Armageddon", then you
can double click the file, accept the changes and Fiddler will be ready.

If Worms Armageddon is installed somewhere else, you will need to edit the
Fiddler.reg file with the location of Worms Armageddon. Directories are
separated by a double slash instead of a single slash in registry files.
When you have done this, save the file and double click Fiddler.reg.

If you're running Windows XP (or any version since Windows 2000), you will need
to install Silkworm. (If you aready have Silkworm, you can skip this step.)

To do this, copy the files in the 'Silkworm' zip file to your Worms Armageddon
directory, and double click 'Silkworm_patch.exe'.

Now the hard bit. To find out which version of Worms Armageddon you have, open
the game and on the main menu, hover over the Worms Armageddon logo.


If you have version 1.0
-----------------------

If you have the original version, then you need to download the update from the
official website:

http://wormsarmageddon.team17.com

And in the box where it says "Running WA v1.0?", you can download the patch to
version 3.0 from there.

After that, make a copy of WA.exe and call it '30.exe', as this is what Fiddler
will be looking for. 


If you have 3.0
---------------

If it says 'Worms Armageddon : V3.00', then all you need to do is to copy the
WA.exe in your Worms Armageddon directory and paste it as '30.exe'.

You can now upgrade to a later version, as Fiddler will still be able to find
version 3.0.


If you have 3.0.5.0 or later
-----------------------------

If it says it's a later version (3.0.5.0 onwards), take a look on your Worms
Armageddon CD at the following directory:

X:\Install\Install

Where X is the drive with the CD in.

If WA.exe is in the directory, copy it to your Worms Armageddon directory as
'30.exe', as this is what Fiddler will be looking for.

If it isn't there, then the only way of obtaining it is to uninstall the beta
versions of Worms Armageddon, and version 3.0 will reappear. You can then
reinstall the beta versions.


If you have a Trymedia, Sold Out or other third party versions of the game
--------------------------------------------------------------------------

Sorry, but Fiddler doesn't support these versions, as they were made after Fiddler
was finished. You can still get a compatible version of Worms Armageddon from the
Team17 store, at https://secure.team17.com/ .


After this, you're ready to use Fiddler!


How to use
==========

Fiddler has so many options that can be tweaked, that it is impractical to list
them all here. Instead I'll list the most important ones.

Fiddler includes an extensive weapons editor, which can let you design brand new
weapons from scratch. You can double click on a weapon's name to bring up a list
of options. Try changing the number of clusters in a cluster bomb for example, or
the number of shots in an uzi, to give you an idea of what it can do.

Also included are general options such as changing gravity, how many pixels the
water rises, and how many points a worm gets for collecting a health crate.

Other options include changing individual worms' health and team weapons, and
introducing events like having earthquakes after the third turn of the game.

When you want to make the changes, click the 'Go!' button and Worms Armageddon
will load, and when you start a game, it will include the changes made in Fiddler.

Try experimenting with new things, as there is always something new you can do in
the program.


Caveats
=======

If you have two versions of Worms Armageddon in one directory, version 3.0 will
be slightly different than before. The stars in the background move a lot faster,
and the mouse eggtimer will appear as a resize arrow.

In Fiddler, you should keep the colour of the water set to blue, as Team17 later
removed the water colours from the later CD's, and will cause a crash for those
without them.

And Fiddler prevents you from playing on Wormnet when it patches the game, because
the other players will experience a desync if they don't have the same settings.


Future
======

Fudge Boy has given the source code of Fiddler to another member of the Worms
community, CyberShadow, who is working with Deadcode on updates to Worms Armageddon,
which include plans to add Fiddler functionality to the game for online play.

WormsMart will continue to be updated with Fiddler files, and can be found at
http://www.edwardwebb.btinternet.co.uk/wormsmart/ .


Credits
=======

James Heather		For the time he devoted to the program, listening to all
			the requests made, and his remarkable skills and patience
			in finding so many things in Worms Armageddon

Allan West		For creating the WormsMart website and allowing the team
			to work on it together, helping James to start work on
			Fiddler, and testing the program for bugs

Adam McNicol		For the time put in to the website, having an excellent
			eye for design, and being a good friend outside of Worms
			as well

Ben Kennish, John Sowler, Jason Blakely, @idboxx and everyone else who was on the
WormsMart team, thank you for being there with us. :-)

And some more:

Joe			Finding out how to get Worms Armageddon working with
			Windows XP

MadEwokHerd		Having fun with Worms and Fiddler way back in 2003, which
			together led to Fudge Boy working on Fiddler for a short
			time

Team17 Staff and	For making one of the most addictive and fun games 
Andy Davidson		out there!

And thank you to everyone who supported Fiddler and WormsMart. Without your support,
we couldn't have done it without you. Thanks for reading, and go play some Worms!