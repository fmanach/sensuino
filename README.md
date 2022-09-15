# Sensuino
_How I hacked a Senseo coffee maker to heat it up remotely._

## Use case 
I am the happy owner of a Senseo coffee maker. The least we can say is that it serves me well as I usually drink at least three cups a day. The only problem I have been having with it is the heating time.

When I come in the kitchen to make myself a coffee, I press the On/Off button and the machine starts heating up the water while I take out a pod of coffee and put it inside, I often end up waiting for a minute or so that the heating ends so I can press the "Run" button.

I though it could be nice if I could start the heating remotely (from my bed or my desk for example), so when I arrive in the kitchen, the machine is ready and I don't have to wait a second before getting my cup filled. 

## Solution
I decided not to do anything about the run buttons that actually pour the coffee because I would always need to put the pod in the machine and a cup on the tray before running it anyway. The only thing I need is a way to remotely push the On/Off button.

## Hardware hack
I will not expand here on the opening of the machine. iFixit and YouTube have good tutorials on this part (which is not that long or difficult anyway). 

Once opened, I soldered a couple of wires to the contacts of the On/Off switch. I used Dupont wires to facilitate the connection later on.

![Picture of the Senseo PCB showing the On/Off button](img/pcb.jpg "Picture of the Senseo PCB showing the On/Off button")

I let the wires exit the machine through an opening already made on the support base.

![Wires coming out the machine](img/wires.png "Wires coming out the coffee maker")

This wires being connected on each port of the On/Off button, connecting them together has the exact same effect as pushing the button. If the machine is off, it turns it on and start heating the water. If the machine is on, it turns it off.

