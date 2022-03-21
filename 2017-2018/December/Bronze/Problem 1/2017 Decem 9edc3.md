# 2017 December Bronze Problem 1

Date: March 20, 2022
Tags: Second Round, Solution

This is essentially a geometry problem. Let’s denote the first billboard as a, the second billboard as b, and the truck as t. Let’s then denote the area of the first billboard as A, the area of the second billboard as B, the area of the truck as T, then the answer is A+B-AUT-BUT-AUB+2*AUBUT. It is significant to think about this problem as geometry so we will not ignore the case where all three areas overlap, which is why we need to add 2*AUBUT at the end.

To calculate the overlap area, it is easier to think about in an analytic way: if point (x,y) is within a, then a.x_ll(lower left)≤x≤ a.x_ur(upper right), a.y_ll≤y≤a.y_ur. So the inequality for x to be within a and b must be: { max(a.x_ll, b.x_ll)≤x≤min(a.x_ur, b.x_ur),

                             max(a.y_ll, b.y_ll)≤y≤min(a.y_ur,  b.y_ur)}

This also works for overlap between b, t, and a, b. To calculate the overlap of a, b, t, just compare the x_ll for all three and do the same for other coordinates.