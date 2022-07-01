# Robotic Arm
Literally a robotic arm, can be controlled with a phone and controller. 

| **Engineer** | **School** | **Area of Interest** | **Grade** |
|:--:|:--:|:--:|:--:|
| Bruce | San Mateo High School | Math | Incoming Sophomore

![Headstone Image](https://lh3.googleusercontent.com/pw/AM-JKLVBKftJ6nHGQmPTOno0GhQzcrVna-7ySq-5CWABdIAhxQ2PipoxJXLZ0n8WiVXtmRXWsRykyucs3HdOHjq474GFSedC-3z9R-ahfI5jAmd5G5NJS-YGbcQeaaoIiuGCuKKmAbgNxbZTun5O9VokOd5p=w1404-h1402-no?authuser=0)
  
# Final Milestone
My final milestone is the increased reliability and accuracy of my robot. I ameliorated the sagging and fixed the reliability of the finger. As discussed in my second milestone, the arm sags because of weight. I put in a block of wood at the base to hold up the upper arm; this has reverberating positive effects throughout the arm. I also realized that the forearm was getting disconnected from the elbow servo’s horn because of the weight stress on the joint. Now, I make sure to constantly tighten the screws at that joint. 

[![Final Milestone](https://res.cloudinary.com/marcomontalbano/image/upload/v1612573869/video_to_markdown/images/youtube--F7M7imOVGug-c05b58ac6eb4c4700831b2b3070cd403.jpg )](https://www.youtube.com/watch?v=F7M7imOVGug&feature=emb_logo "Final Milestone"){:target="_blank" rel="noopener"}

# Second Milestone
My final milestone is the increased reliability and accuracy of my robot. I ameliorated the sagging and fixed the reliability of the finger. As discussed in my second milestone, the arm sags because of weight. I put in a block of wood at the base to hold up the upper arm; this has reverberating positive effects throughout the arm. I also realized that the forearm was getting disconnected from the elbow servo’s horn because of the weight stress on the joint. Now, I make sure to constantly tighten the screws at that joint.

[![Third Milestone](https://res.cloudinary.com/marcomontalbano/image/upload/v1612574014/video_to_markdown/images/youtube--y3VAmNlER5Y-c05b58ac6eb4c4700831b2b3070cd403.jpg)](https://www.youtube.com/watch?v=y3VAmNlER5Y&feature=emb_logo "Second Milestone"){:target="_blank" rel="noopener"}
# First Milestone
  
My first milestone was assembling the full arm and making it move with a controller. The actual mechanical assembly was a pain because the parts weren't very good and there were a lot of parts that did not fit together. I had to file away at a servo mount for half an hour to get it to fit into a baseplate. Next came the software. First, my original Arduino board had a faulty voltage regulator, so I had to get a new one. The code provided by the kit makers was really asinine, so I decided to make my own. My original code had a lot of issues, but I managed to solve all of them and even optimize it a bit with functions. For example, because I was mapping the value of the joysticks' coordinates to the degrees on the corresponding servo, whenever I let go of the joystick and it would return to its original posistion, and because I was mapping it, the servo would return as well. Essentially, movements made were not permanent, and would not stay if I was not holding the servo in that position. I solved by using the button fuctionality of the joysticks. If you press down, the joystick actually activates a push switch. I only let the servos map if this button was also being pushed down, thus when the joystick snaps back nothing happens since the button is up. This has the added benefit of making the button a "reset" in some ways. If I press it down while the joystick is in its resting position, it will reset the corresponding servos to THEIR original position, allowing me to reset the entire arm. 


[![First Milestone](https://res.cloudinary.com/marcomontalbano/image/upload/v1612574117/video_to_markdown/images/youtube--CaCazFBhYKs-c05b58ac6eb4c4700831b2b3070cd403.jpg)](https://www.youtube.com/watch?v=CaCazFBhYKs "First Milestone"){:target="_blank" rel="noopener"}

# Starter Project

I made the useless machine, which works through a 2-switch system. When in resting position, the arm's unique design keeps a snap switch turned off. Once the switch on the top is manually turned on, the arm will move and get off the snap switch, meaning that both switches are now on. Once it turns the other switch off, it will still be able to move back into the box because the snap switch is still on, and it changes the current to move the motor in a different direction and changes the LED color.

[![Starter Project](https://res.cloudinary.com/marcomontalbano/image/upload/v1655500442/video_to_markdown/images/youtube--Y4uDYHtt_Gk-c05b58ac6eb4c4700831b2b3070cd403.jpg)](https://www.youtube.com/watch?v=Y4uDYHtt_Gk "")

