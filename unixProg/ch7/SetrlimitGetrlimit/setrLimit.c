#include<stdio.h>
#include<sys/resource.h>
// getrlimit() are setrlimit() are pre-defined in "sys/resource.h" header
/*struct rlimit { 
                rlim_t rlim_cur;   --> Soft limit 
                rlim_t rlim_max;   --> Hard limit (ceiling for rlim_cur)  
            };  
*/

// Here CPU limit is checked and then changed to 1 second
int main () 
{ 
   // Define and object of structure rlimit 
   struct rlimit rl; 
  
   // First get the time limit on CPU 
   getrlimit (RLIMIT_CPU, &rl); 
   // Initial CPU time is -1 because there is no limit to start-off
   printf("\n Default value is : %d\n", (int)rl.rlim_cur); 
  
   // Change the time limit 
   rl.rlim_cur = 1; 
  
   // Now call setrlimit() to set the changed value 
   setrlimit (RLIMIT_CPU, &rl); 
  
   // Again get the limit and check 
   getrlimit (RLIMIT_CPU, &rl); 
  
   printf("\n Default value now is : %d\n", (int)rl.rlim_cur); 
  
   // Simulate a long time consuming work - an infinite loop :);
   while (1); 
  
   return 0; 
 }