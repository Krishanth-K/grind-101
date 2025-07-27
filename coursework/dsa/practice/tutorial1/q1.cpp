#include <iostream>
#include <vector>

// procedure sort(arr)
// {
// 	for (i = 0 ..len(arr))
// 	{
// 		if (arr[i] == 'c') arr[i] = 0;
// 		if (arr[i] == 'y') arr[i] = 1;
// 		if (arr[i] == 'o') arr[i] = 2;
// 	}
//
// 	for (int i = 0 ..len(arr) - 2)
// 	{
// 		for (int j = 0 ..len(arr) - i - 2)
// 		{
// 			if (arr[j] < arr[j + 1])
// 			{
// 				swap(arr[j], arr[j + 1]);
// 			}
// 		}
// 	}
//
// 	for (i = 0 ..len(arr))
// 	{
// 		if (arr[i] == 0) arr[i] = 'c';
// 		if (arr[i] == 1) arr[i] = 'y';
// 		if (arr[i] == 2) arr[i] = 'o';
// 	}
// }

// procedure addAtPos(head, pos)
// {
// 	// add a song at position pos
// 	if (head == NULL) return false;
// 	count < -0;
// 	temp < -head;
//
// 	while (count < pos - 1)
// 	{
// 		if (temp == NULL) return false;
// 		count < -count + 1;
// 		temp < -temp.next;
// 	}
// 	newNode < -Node();
//
// 	// add the node
// 	temp.next.prev < -newNode;
// 	newNode.next < -temp.next;
// 	newNode.prev < -temp;
// 	temp.next < -newNode;
//
// 	return true;
// }

// procedure delAtPos(head, pos)
// {
// 	if (head == NULL)
// 		return false;
// 	temp <- head;
// 	count <- 1;
//
// 	while (count < pos - 1)
// 	{
// 		temp <- temp.next;
// 		if (temp == NULL)
// 			return false;
// 		count <- count + 1;
// 	}
//
// 	if (temp.next.next == NULL || temp.next == NULL)
// 		return false;
// 	temp.next.next.prev = temp;
//
// 	toDel <- temp.next;
// 	temp.next <- temp.next.next;
//
// 	delete toDel;
// }

// procedure next(currSong)
// {
//     // move currSong pointer to next
//     if (currSong == NULL || currSong.next == NULL) return false;
//
//     currSong <- currSong.next;
//     return true;
// }

// procedure prev(currSong)
// {
//     // move currSong pointer to prev
//     if (currSong == NULL || currSong.prev == NULL) return false;
//
//     currSong <- currSong.prev;
//     return true;
// }

// procedure bells(head)
// {
// 	// find when all ring together
// 	temp <- head;
// 	dur <- 0;
// 	lcm <- 90; // lcm of all bells
//
// 	while (true)
// 	{
// 		if (temp == NULL)
// 			return 0;
//
// 		dur <- dur + temp.duration + 7;
//
//         nextBell <- ceil(dur / 90) * 90;
//         if (nextBell < dur + 7) return nextBell;
//
// 		temp <- temp.next;
// 	}
// }

int main() {}
