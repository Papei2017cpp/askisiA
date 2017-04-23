# Terminal Program for FlightsAgency

* Main menu

![img](http://i.imgur.com/ryLV4I9.png)
#### Its a simple main menu where you can select A to import a new flight
code with all details required , S to search for a flightcode to show
nothing if the code doesnt exist or the details given ,R to reserve a seat ,C to cancel a reservation and D to delete the flight code and details as well as the queue line of this flightcode.
and whenever you want to quit press X

*Usage

lets say that we type 
```
A
```
#### Then this dialog will show up:
![img](http://i.imgur.com/aJfMd6g.png)
#### Fill it randomly like the image below:
![img](http://i.imgur.com/sOT0In7.png)
#### and now its done you have imported a flight
and the "SELECT :" will appear again , and you can give the next command
to continue the example i am going to add one more flight(with code 400)...

lets say that we type 
```
S
```
#### Then its going to ask as to give the FLIGHTCODE to look for , i typed 300 and that happened :
![img](http://i.imgur.com/999qEs9.png)
#### all the flight details that we gave are shown

#### but if i give 400 this happening
![img](http://i.imgur.com/C0t6aNW.png)
#### so we call it 
### BUG NO 1

We can also type the command for example to delete D300 and it will just be ugly 
```
SELECT:
D300
GIVE FLIGHTCODETHE FLIGHTHAS BEEN DELETED 
```
but no problem there, the problem is when i type D400 so maybe the Search functionality is broken
#### so we call it
### BUG NO 2


#### If we type R and we give all the flightcode and the name 'p' and 
last name 'o' we can add a reservation and so on..
but i we try to delete the 'p'  'o' we got the fantastic :
### BUG NO 3
