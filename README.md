andro-lock
==========

SDL simple screen locker loosely based on Android locker

Overview
--------

We all know how it is important to lock our work station when leaving it. While
the operating system or distribution can provide built-in tools to lock the
screen and unlock it with a password, one could prefer to unlock it with the
pointer of the mouse. That is what andro-lock offers.

![andro-lock example](https://github.com/skorpios/andro-lock/raw/master/res/example.png)

For security reasons (and because it was easier :p), the buttons
don't change their color during unlocking process.

How it works
------------

When launched, the program tries to read a combination from the file password.txt.
Clicking one time on the window enables the locking of the screen.
Every time we click, the program verifies if the combination read in the file
match the combination of clicks we did.

For example, with the following password.txt :

    	     000000000

We have to click 9 times on the first button.
