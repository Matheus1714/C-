#include <iostream>
#include <cstdio>
using namespace std;
 
int a [30] [30];
int n;
int first_x;
int first_y;
int second_x;
int second_y;
 
void output ()
{
    for ( int i = 0; i < n; i++ ) {
        printf ("%d:", i);
        for ( int j = 0; a [i] [j] != -1; j++ )
            printf (" %d", a [i] [j]);
        printf ("\n");
    }
 
    //printf ("\n");
}
 
void constructor ()
{
    for ( int i = 0; i < n; i++ ) {
        a [i] [0] = i;
        a [i] [1] = -1;
    }
}
 
bool validity (int first, int second)
{
    if ( first == second )
    return false;
 
    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; a [i] [j] != -1; j++ ) {
            if ( first == a [i] [j] ) {
                for ( int k = 0; a [i] [k] != -1; k++ ) {
                    if ( second == a [i] [k] )
                        return false;
                }
            }
        }
    }
 
    return true;
}
 
 
void find (int first, int second)
{
    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; a [i] [j] != -1; j++ ) {
            if ( a [i] [j] == first ) {
                first_x = i;
                first_y = j;
            }
 
            else if ( a [i] [j] == second ) {
                second_x = i;
                second_y = j;
            }
        }
    }
}
 
void move_onto_method (int first, int second)
{
    if ( !validity (first, second) )
    return;
 
    find (first, second);
 
    //output ();
 
    for ( int i = first_y + 1; a [first_x] [i] != -1; i++ ) {
        a [a [first_x] [i]] [0] = a [first_x] [i];
        a [a [first_x] [i]] [1] = -1;
    }
 
    a [first_x] [first_y] = -1;
 
    for ( int i = second_y + 1; a [second_x] [i] != -1; i++ ) {
        a [a [second_x] [i]] [0] = a [second_x] [i];
        a [a [second_x] [i]] [1] = -1;
    }
 
    a [second_x] [second_y + 1] = first;
    a [second_x] [second_y + 2] = -1;
 
}
 
 
void move_over_method (int first, int second)
{
    if ( !validity (first, second) )
    return;
 
    find (first, second);
 
    for ( int i = first_y + 1; a [first_x] [i] != -1; i++ ) {
        a [a [first_x] [i]] [0] = a [first_x] [i];
        a [a [first_x] [i]] [1] = -1;
    }
 
    a [first_x] [first_y] = -1;
 
    second_y++;
    while ( a [second_x] [second_y] != -1 )
        second_y++;
 
    a [second_x] [second_y] = first;
    a [second_x] [++second_y] = -1;
}
 
 
void pile_onto_method (int first, int second)
{
    if ( !validity (first, second) )
    return;
 
    find (first, second);
 
    for ( int i = second_y + 1; a [second_x] [i] != -1; i++ ) {
        a [a [second_x] [i]] [0] = a [second_x] [i];
        a [a [second_x] [i]] [1] = -1;
    }
 
    for ( int i = first_y; a [first_x] [i] != -1; i++ )
        a [second_x] [++second_y] = a [first_x] [i];
 
    a [second_x] [++second_y] = -1;
    a [first_x] [first_y] = -1;
 
}
 
 
void pile_over_method (int first, int second)
{
    if ( !validity (first, second) )
    return;
 
    find (first, second);
 
    second_y++;
    while ( a [second_x] [second_y] != -1 )
        second_y++;
 
    for ( int i = first_y; a [first_x] [i] != -1; i++ )
        a [second_x] [second_y++] = a [first_x] [i];
 
    a [second_x] [second_y] = -1;
    a [first_x] [first_y] = -1;
}
 

int main ()
{
    
    while ( cin >> n ) {
 
        constructor ();
 
        
 
        string move_pile;
        int first;
        string onto_over;
        int second;
 
        while ( cin >> move_pile ) {
 
            if ( move_pile == "quit" )
                break;
            cin >> first;
            cin >> onto_over;
            cin >> second;
 
            if ( move_pile == "move" && onto_over == "onto" ) {
                move_onto_method (first, second);
            }
 
            else if ( move_pile == "move" && onto_over == "over" ) {
                move_over_method (first, second);
            }
 
            else if ( move_pile == "pile" && onto_over == "onto" ) {
                pile_onto_method (first, second);
            }
 
            else if ( move_pile == "pile" && onto_over == "over" ) {
                pile_over_method (first, second);
            }
 
            //output ();
        }
 
        output ();
    }
 
    return 0;
}