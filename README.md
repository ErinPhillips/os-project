### Final Project - CSCI 340
### Erin Phillips and Brandon Beck
### Cache and Main Memory
#
### What is the size of a cache block?
We know that the size of the cache block is 256 bytes. We were unable to obtain this result with our expirements. The program is able to utilize cache efficiently until it requires a new block. We attempted to record the times by comparing random accesses to an array but could not get the functionality to execute in a desired way. Our asumption is that the time taking to access cache memory slows when it nears requiring a new block - this was difficult to prove with our program. 

### What is the size of cache?
Again, this question was difficult to prove with the limited knowledge the two of us have manipulating code in C in an efficient manner. We ran into many simple errors that inhibited us from obtaining desired results. 

### How long does it take to access main memory?
The average time it takes to access main memory is about 28 nanoseconds.  We populated two arrays that forced one to access main memory (since cache should have been full). Again our results varied. 

### How long would it take to access cache memory?
We were able to achieve results with this function. The average time it takes to access cache memory is about 1-2 nanoseconds. We populated an array with random integers and made small changes to each one. As an element was modofied, the next bytes were loaded into the cache block. The results we recieve were continuously inconsistent however we believe our results prove the answer to the question. 
#
### Final thoughts:

This project was extremely difficult to execute. Both of us have been extremely busy during this semester and time was not in out favor, even with the generous timeframe. Many methods and attempts were discarded and we ultimatley chose to remove two functions all together leaving only the average cache and main memory time functions for your review. 1000 trials were ran to achieve accuracy. Again, this was difficult and we feel we both have learned a significant amount about cache and main memory and the relationship beetween the two. We certainly have room for improvement in coding in C and believe if we had fine tuned our skills, we could have fully implemented the project requirements in an improved manner. 
