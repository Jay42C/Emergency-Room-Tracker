This C++ ﻿program tracks patients entering and leaving a hospital emergency room. Patients coming into the emergency room are assigned a priority by the triage team and then wait in the waiting
room for a healthcare provider. When a healthcare provider becomes available, the patient with the highest priority is called and removed from the waiting room. A heap is a good choice to implement a priority queue, which is what we need for this problem. Implement a
class for an array. It should support the following operations at minimum:

add(newPaitent: Patient): boolean 
^ adds a new patient to the waiting room heap. returns true if successful, false if not.

peekTop(): Patient 
retums the next patient to be served, i.e. ﻿the patient with highest priority in the heap (does not remove the patient from the waiting room heap)

remove(): boolean 
reserves the next patient, i.e. ﻿removes the patient with the highest priority from the waiting room heap. returns true if successful, false if not.


Each Patient needs to have both a priority and data. For this assignment, to keep things tractable, you can use a hack. Each Patient in the heap will be a string. The first character of the string is a single digit integer indicating
the priority, followed by a space, followed by the first name of the patient. The priority can be any integer between 1  ﻿and 9, ﻿with 9 ﻿being the highest priority and 1 ﻿being the lowest. For example, we could have three
patients in the waiting room:

" 9 ﻿Mary" -- ﻿patient Mary with priority 9

"5 Bob" -- ﻿patient Bob with priority 5

"1 ﻿Max"-- ﻿patient Max with priority 1

The C++ ﻿string class can compare strings using the < ﻿and > ﻿operators, and the above strings are in fact sorted from highest to lowest due to the leading integers. Your heap array can thus be an array of string objects.
