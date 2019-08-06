# Roulette
Roulette simulation programmed in C++ and played through a command line.

## Overview
This isn't really an object-oriented program, in fact there are no classes written for it specifically.
Instead it's really a structured program, using a collection of functions within a while loop.
All game information exists as a primitive that gets passed around as function inputs and outputs.

## How to play
It is a Euro-style roulette wheel with no double zero option.
You can bet on a range of options, but you can't place any bets once the wheel starts spinning.
Additionally, you can't place custom bets.

## How it works
The program initializes all the required variables and then enters a while loop.
The loop runs through the menu, and unless the user indicates they want to quit, runs through the loop of each method.
It has methods for acquiring all necessary information from the user: bet amount, what to bet on, and a specific number if appropriate.
After spinning, it announces the results. If the user won, it also rewards money as appropriate.

## Future plans
As of 5 August 2019, this program works fine on my home PC but not on my laptop, despite that both are running Windows 10.
The error messages make it look that there are dependencies missing on the laptop, even though I have already installed everything that seems relevant.
For now I'll have to see what I can do to fix it.