
// Including necessary header files for the program
#include <graphics.h>   // For graphics-related functions
#include <stdlib.h>     // For standard library functions like srand
#include <stdio.h>      // For standard input and output functions
#include <conio.h>      // For console input/output functions
#include <iostream>     // For input/output stream functions
#include <time.h>       // For time-related functions
#include <windows.h>    // For Windows API functions

using namespace std;

// Function to initialize the random number generator based on the current time
void random()
{
    srand((unsigned)time(0));
}





// Function to interchange the values of a 2D array 'a' with random non-repeating numbers from 1 to 9
// The function also updates another 2D array 'q' with the new values if they are non-zero
void interchange(int (*a)[9], int (*q)[9])
{
    int arr[9]; // Array to store random non-repeating numbers from 1 to 9
    int i, j;   // Loop variables

    // Generate 9 random non-repeating numbers and store them in 'arr'
    for (i = 0; i < 9; i++)
    {
        do
        {
            // Generate a random number from 1 to 9 using the 'rand()' function and store it in 'arr[i]'
            arr[i] = rand() % 9 + 1;

            // Check if the generated number 'arr[i]' is already present in the 'arr' array
            // If it is, generate another random number until a non-repeating one is found
            for (j = 0; j < i; j++)
            {
                if (arr[i] == arr[j])
                    break;
            }
        } while (j != i); // Repeat the process until a non-repeating number is found for 'arr[i]'
    }

    // Interchange the values in array 'a' with the values from 'arr'
    for (i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            // Replace the element at 'a[i][j]' with the value at 'arr[a[i][j]-1]'
            // Subtracting 1 because the random numbers are generated from 1 to 9, but array indices are from 0 to 8
            a[i][j] = arr[a[i][j] - 1];

            // If the corresponding element in 'q' is non-zero, update it with the new value from 'a'
            if (q[i][j] != 0)
                q[i][j] = a[i][j];
        }
    }
    return; // The function does not return anything, so we can simply use 'return;'
}






// Function to exchange rows within its set of three for two 2D arrays 'a' and 'q'
void row(int (*a)[9], int (*q)[9])
{
    // Generate random indices for the principal row, and two sub-rows within its set of three
    int principal = rand() % 3; // Random number from 0 to 2 (inclusive)
    int sub = rand() % 3;       // Random number from 0 to 2 (inclusive)
    int sub1;                   // Another sub-index

    // Ensure that sub1 is different from sub
    do
    {
        sub1 = rand() % 3;
    } while (sub1 == sub);

    // Calculate the actual row indices to be exchanged
    int row1 = principal * 3 + sub;
    int row2 = principal * 3 + sub1;

    // Exchange the rows for both the 'a' and 'q' arrays
    for (int j = 0; j < 9; j++)
    {
        // For the 'a' array (solution)
        int temp = a[row1][j];
        a[row1][j] = a[row2][j];
        a[row2][j] = temp;

        // For the 'q' array (question)
        temp = q[row1][j];
        q[row1][j] = q[row2][j];
        q[row2][j] = temp;
    }
}





// Function to exchange columns within its set of three for two 2D arrays 'a' and 'q'
void col(int (*a)[9], int (*q)[9])
{
    // Generate random indices for the principal column, and two sub-columns within its set of three
    int principal = rand() % 3; // Random number from 0 to 2 (inclusive)
    int sub = rand() % 3;       // Random number from 0 to 2 (inclusive)
    int sub1;                   // Another sub-index

    // Ensure that sub1 is different from sub
    do
    {
        sub1 = rand() % 3;
    } while (sub1 == sub);

    // Calculate the actual column indices to be exchanged
    int col1 = principal * 3 + sub;
    int col2 = principal * 3 + sub1;

    // Exchange the columns for both the 'a' and 'q' arrays
    for (int j = 0; j < 9; j++)
    {
        // For the 'a' array (solution)
        int temp = a[j][col1];
        a[j][col1] = a[j][col2];
        a[j][col2] = temp;

        // For the 'q' array (question)
        temp = q[j][col1];
        q[j][col1] = q[j][col2];
        q[j][col2] = temp;
    }
}



//for whole 3*9 swap with next 3*9
// Function to exchange rows within two sets of three rows for two 2D arrays 'a' and 'q'
void rows3(int (*a)[9], int (*q)[9])
{
    // Generate random indices for two sub-rows within their sets of three
    int sub = rand() % 3; // Random number from 0 to 2 (inclusive)
    int sub1;            // Another sub-index

    // Ensure that sub1 is different from sub
    do
    {
        sub1 = rand() % 3;
    } while (sub1 == sub);

    // Calculate the starting row indices for each set of three rows
    int start_row1 = sub * 3;
    int start_row2 = sub1 * 3;

    // Exchange the rows for both the 'a' and 'q' arrays within each set of three rows
    int temp;
    for (int i = start_row1, k = start_row2; i < start_row1 + 3 && k < start_row2 + 3; i++, k++)
    {
        for (int j = 0; j < 9; j++)
        {
            // For the 'a' array (solution)
            temp = a[i][j];
            a[i][j] = a[k][j];
            a[k][j] = temp;

            // For the 'q' array (question)
            temp = q[i][j];
            q[i][j] = q[k][j];
            q[k][j] = temp;
        }
    }
}





//for whole 3*9 swap with next 3*9
// Function to exchange columns within two sets of three columns for two 2D arrays 'a' and 'q'
void cols3(int (*a)[9], int (*q)[9])
{
    // Generate random indices for two sub-columns within their sets of three
    int sub = rand() % 3; // Random number from 0 to 2 (inclusive)
    int sub1;            // Another sub-index

    // Ensure that sub1 is different from sub
    do
    {
        sub1 = rand() % 3;
    } while (sub1 == sub);

    // Calculate the starting column indices for each set of three columns
    int start_col1 = sub * 3;
    int start_col2 = sub1 * 3;

    // Exchange the columns for both the 'a' and 'q' arrays within each set of three columns
    int temp;
    for (int i = start_col1, k = start_col2; i < start_col1 + 3 && k < start_col2 + 3; i++, k++)
    {
        for (int j = 0; j < 9; j++)
        {
            // For the 'a' array (solution)
            temp = a[j][i];
            a[j][i] = a[j][k];
            a[j][k] = temp;

            // For the 'q' array (question)
            temp = q[j][i];
            q[j][i] = q[j][k];
            q[j][k] = temp;
        }
    }
}



int main(void)
{
    // Open the Sudoku.exe application
    system("start Sudoku.exe");

    // Output "Running..."
    cout << "Running...";

    // Call the 'random' function to initialize the random number generator
    random();

    int ne = 1; // Initialize the variable 'ne' to 1
    int gdriver = DETECT, gmode, errorcode;
    char path[] = "C:\\Program Files (x86)\\CodeBlocks\\MinGW\\lib\\libbgi.a";

    // Initialize the graphics mode using the 'initgraph' function
    initgraph(&gdriver, &gmode, path);

    /* read result of initialization */
    errorcode = graphresult();
    if (errorcode != grOk) // Check if there was an error during graphics initialization
    {
        printf("Graphics error: %s\n", grapherrormsg(errorcode));
        printf("Press any key to halt:");
        getch();
        exit(1); // Terminate the program with an error code
    }

    while (ne)
    {
        int midx, midy;
        int radius = 100, fl = 0;
        int i, j, tempx = 0, tempy = 0;
        int activex = 0, activey = 0;
        char inp[5];
        char arrow, ch;
        int a[9][9]; // Array to store the solution for the Sudoku puzzle
        int q[9][9], cpy[9][9]; // Arrays to store the puzzle and a copy of it
        int esc = 0, ng = 0;

        int cl = 3; // Color for input

   // -------------------------------------------------LOADING--------------------------------------------------------------
        FILE *fp;
        if ((fp = fopen("students.txt", "r")) == NULL)
        {
            cout << "error";
        }
        for (i = 0; i < 9; i++)
            for (j = 0; j < 9; j++)
            {
                fscanf(fp, "%d", &a[i][j]);
            }
        for (i = 0; i < 9; i++)
            for (j = 0; j < 9; j++)
            {
                fscanf(fp, "%d", &q[i][j]);
            }

        fclose(fp);
        // ---------------------------------------------------------------------------------------------------------------------

        // -----------------------------------------------------PROCESSING---------------------------------------------------------
        for (j = 0; j < 10000; j++)
        {
            interchange(a, q);
            row(a, q);
            col(a, q);
            rows3(a, q);
            cols3(a, q);
        }
        // ---------------------------------------------------------------------------------------------------------------------

        // ------------------------------------------------------UPDATE------------------------------------------------------------
        if ((fp = fopen("students.txt", "w")) == NULL)
        {
            cout << "error";
        }
        for (i = 0; i < 9; i++)
        {
            for (j = 0; j < 9; j++)
                fprintf(fp, "%d ", a[i][j]);
        }
        for (i = 0; i < 9; i++)
        {
            for (j = 0; j < 9; j++)
                fprintf(fp, "%d ", q[i][j]);
        }
        fclose(fp);

        for (i = 0; i < 9; i++)
            for (j = 0; j < 9; j++)
            {
                cpy[i][j] = q[i][j];
            }
        // ---------------------------------------------------------------------------------------------------------------------

        /* initialize graphics and local variables */

        // Clear the graphics screen
        cleardevice();

        // Calculate the center of the graphics screen
        midx = getmaxx() / 2 - 153;
        midy = getmaxy() / 2 - 153;

        // Drawing the Sudoku grid
        setcolor(YELLOW);
        setlinestyle(0, 0, 4);
        line(0, 2, getmaxx(), 2);
        rectangle(0, 0, getmaxx(), getmaxy());
        setcolor(WHITE);
        setlinestyle(0, 0, 0);
        settextstyle(6, HORIZ_DIR, 5);

        setcolor(9);
        char text[] = "SUDOKU";
        outtextxy(midx + 20, 20, text);
        setcolor(WHITE);

        // Draw the Sudoku grid
        for (i = midx, j = 0; i <= midx + 306; i = i + 34, j++)
        {
            if (j % 3 == 0)
                setlinestyle(0, 0, 3);
            line(i, midy, i, midy + 306);
            setlinestyle(0, 0, 0);
        }
        for (i = midy, j = 0; i <= midy + 306; i = i + 34, j++)
        {
            if (j % 3 == 0)
                setlinestyle(0, 0, 3);
            line(midx, i, midx + 306, i);
            setlinestyle(0, 0, 0);
        }

        // Draw the numbers for the initial puzzle
        for (i = 0; i < 9; i++)
            for (j = 0; j < 9; j++)
            {
                if (q[i][j] == 0)
                    continue;
                sprintf(inp, "%d", q[i][j]);
                outtextxy(midx + 5 + i * 34, midy + 5 + j * 34, inp);
            }

        // Draw the menu options
        char textSubmit[] = "S-Submit";
        char textNewGame[] = "N-New Game";
        char textExit[] = "Esc-Exit";
        settextstyle(0, HORIZ_DIR, 2);
        outtextxy(10, 200, textSubmit);
        outtextxy(10, 230, textNewGame);
        outtextxy(10, 260, textExit);

        // Movement of the box
        setcolor(WHITE);
        settextstyle(0, HORIZ_DIR, 3);

        while (1)
        {
            if (kbhit())
            {
                // Stores the pressed key in 'ch'
                ch = getch();
                if (int(ch) == 0)
                    continue;

                // -------------------------------------------------------submssion-------------------------------------------------
                if (ch == 's')
                {
                    fl = 0;
                    for (i = 0; i < 9; i++)
                        for (j = 0; j < 9; j++)
                        {
                            if (a[i][j] != q[i][j])
                            {
                                fl = 1;
                                break;
                            }
                        }
                    if (fl == 0)
                    {
                        //cleardevice();
                        setcolor(6);
                        settextstyle(1, HORIZ_DIR, 2);
                        char textWin[] = "HURRAY!!!! YOU SOLVED IT";
                        outtextxy(170, midy + 330, textWin);
                    }
                    else
                    {
                        //cleardevice();
                        setcolor(BLUE);
                        setlinestyle(0, 0, 4);
                        rectangle(90, midy + 320, 530, midy + 360);
                        setcolor(RED);
                        settextstyle(0, HORIZ_DIR, 2);
                        char textLose[] = "OOPS!!!! THAT'S WRONG";
                        outtextxy(170, midy + 330, textLose);

                        setfillstyle(SOLID_FILL, BLACK);
                        delay(1000);
                        floodfill(100, midy + 325, BLUE);
                        setcolor(GREEN);
                        char Try[] = "COMEON YOU CAN!!!!!";
                        outtextxy(180, midy + 330, Try);
                        settextstyle(0, HORIZ_DIR, 3);
                    }
                }
                if (ch == 'n' || ch == 'N')
                {
                    break;
                }

                // Terminates the loop when escape is pressed
                tempx = activex;
                tempy = activey;
                if (int(ch) == 27)
                {
                    cleardevice();
                    setcolor(GREEN);
                    settextstyle(0, HORIZ_DIR, 3);
                    char textTY[] = "THANKYOU FOR PLAYING";
                    outtextxy(midx - 100, midy, textTY);
                    setcolor(RED);
                    settextstyle(0, 0, 3);
                    char press[] = "Press any key";
                    outtextxy(midx - 30, midy + 100, press);
                    ne = 0;
                    break;
                }

                if (int(ch) == 72)
                {
                    setfillstyle(SOLID_FILL, 0);
                    floodfill(midx + 17 + activex * 34, midy + 17 + activey * 34, WHITE);
                    if (q[activex][activey] != 0)
                    {
                        if (cpy[activex][activey] == 0)
                            setcolor(cl);
                        else
                            setcolor(WHITE);
                        sprintf(inp, "%d", q[activex][activey]);
                        outtextxy(midx + 5 + activex * 34, midy + 5 + activey * 34, inp);
                    }

                    if (activey == 0)
                        activey = 8;
                    else
                        activey--;
                    //  gotoxy(midx+15+activex*30,midy+15+activey*30);
                    setfillstyle(SOLID_FILL, RED);
                    if (cpy[activex][activey] == 0)
                        floodfill(midx + 17 + activex * 34, midy + 17 + activey * 34, WHITE);
                    sprintf(inp, "%d", q[activex][activey]);
                    if (q[activex][activey] != 0)
                    {
                        if (cpy[activex][activey] == 0)
                            setcolor(cl);
                        else
                            setcolor(WHITE);
                        outtextxy(midx + 5 + activex * 34, midy + 5 + activey * 34, inp);
                    }
                }
                if (int(ch) == 80)
                {
                    setfillstyle(SOLID_FILL, 0);
                    floodfill(midx + 17 + activex * 34, midy + 17 + activey * 34, WHITE);
                    if (q[activex][activey] != 0)
                    {
                        if (cpy[activex][activey] == 0)
                            setcolor(cl);
                        else
                            setcolor(WHITE);
                        sprintf(inp, "%d", q[activex][activey]);
                        outtextxy(midx + 5 + activex * 34, midy + 5 + activey * 34, inp);
                    }

                    if (activey == 8)
                        activey = 0;
                    else
                        activey++;
                    // gotoxy(midx+15+activex*30,midy+15+activey*30);
                    setfillstyle(SOLID_FILL, RED);
                    if (cpy[activex][activey] == 0)
                        floodfill(midx + 17 + activex * 34, midy + 17 + activey * 34, WHITE);
                    if (q[activex][activey] != 0)
                    {
                        if (cpy[activex][activey] == 0)
                            setcolor(cl);
                        else
                            setcolor(WHITE);
                        sprintf(inp, "%d", q[activex][activey]);
                        outtextxy(midx + 5 + activex * 34, midy + 5 + activey * 34, inp);
                    }
                }
                if (int(ch) == 75)
                {
                    setfillstyle(SOLID_FILL, 0);
                    floodfill(midx + 17 + activex * 34, midy + 17 + activey * 34, WHITE);
                    if (q[activex][activey] != 0)
                    {
                        if (cpy[activex][activey] == 0)
                            setcolor(cl);
                        else
                            setcolor(WHITE);
                        sprintf(inp, "%d", q[activex][activey]);
                        outtextxy(midx + 5 + activex * 34, midy + 5 + activey * 34, inp);
                    }

                    if (activex == 0)
                        activex = 8;
                    else
                        activex--;
                    // gotoxy(midx+15+activex*30,midy+15+activey*30);
                    setfillstyle(SOLID_FILL, RED);
                    if (cpy[activex][activey] == 0)
                        floodfill(midx + 17 + activex * 34, midy + 17 + activey * 34, WHITE);
                    if (q[activex][activey] != 0)
                    {
                        if (cpy[activex][activey] == 0)
                            setcolor(cl);
                        else
                            setcolor(WHITE);
                        sprintf(inp, "%d", q[activex][activey]);
                        outtextxy(midx + 5 + activex * 34, midy + 5 + activey * 34, inp);
                    }
                }

                 if(int(ch)==77)
                 {
                    setfillstyle(SOLID_FILL,0);
                    floodfill(midx+17+activex*34,midy+17+activey*34,WHITE);
                    if(q[activex][activey]!=0)
                       {
                           if(cpy[activex][activey]==0)
                            setcolor(cl);
                           else
                            setcolor(WHITE);
                            sprintf(inp,"%d",q[activex][activey]);
                       outtextxy(midx+5+activex*34,midy+5+activey*34,inp);
                       }

                    if(activex==8)
                       activex=0;
                    else
                       activex++;
                      // gotoxy(midx+15+activex*30,midy+15+activey*30);
                    setfillstyle(SOLID_FILL,RED);
                   if(cpy[activex][activey]==0)
                    floodfill(midx+17+activex*34,midy+17+activey*34,WHITE);
                    if(q[activex][activey]!=0)
                       {
                           if(cpy[activex][activey]==0)
                            setcolor(cl);
                           else
                            setcolor(WHITE);
                            sprintf(inp,"%d",q[activex][activey]);
                       outtextxy(midx+5+activex*34,midy+5+activey*34,inp);
                       }



                 }
                 if(int(ch)>=int('1')&&int(ch)<=('9')&&cpy[activex][activey]==0)
                 {
                     setfillstyle(SOLID_FILL,BLACK);
                     floodfill(midx+17+activex*34,midy+17+activey*34,WHITE);
                      q[activex][activey]=int(ch)-int('1')+1;
                      sprintf(inp,"%d",q[activex][activey]);
                       setcolor(cl);
                       settextstyle(0,HORIZ_DIR,3);
                      outtextxy(midx+5+tempx*34,midy+5+tempy*34,inp);
                     fl=1;

                 }


        // Check if a key has been pressed using kbhit() function
        // If a key is pressed, the control enters this block

        // Restore the original value of the cell where the cursor was previously located
        // if the value in the puzzle matrix 'q' is not 0 (i.e., it was not an empty cell)
        if (q[tempx][tempy] != 0)
        {
            // Set the text color to white
            setcolor(WHITE);
            // Convert the integer value of 'q[tempx][tempy]' to a character array 'inp'
            sprintf(inp, "%d", q[tempx][tempy]);
            // Display the value of 'q[tempx][tempy]' at the correct cell on the grid
            outtextxy(midx + 5 + tempx * 34, midy + 5 + tempy * 34, inp);
        }

        // Reset the 'fl' (flag) variable to 0
        fl = 0;

        // Display the current value of 'fl' (which is 0) indicating no key was pressed
        cout << "\nKey pressed= " << fl;
    }
}







// Wait for user input (arrow keys or other keys)
cin >> arrow;

// Check if the pressed key is 'e'
if (arrow == 'e')
    // Set the 'fl' (flag) variable to 1
    fl = 1;

// Check if the pressed key is the special character corresponding to the up arrow (ASCII value 24)
if (arrow == 24)
{
    // Restore the color of the previous cell where the cursor was located
    setfillstyle(SOLID_FILL, 0);
    floodfill(midx + 15 + activex * 30, midy + 15 + activey * 30, WHITE);

    // Move the cursor up (decrease the 'activex' variable)
    if (activex == 0)
        activex = 8;
    else
        activex--;

    // Highlight the new cell where the cursor is located with a red color
    setfillstyle(SOLID_FILL, RED);
    floodfill(midx + 15 + activex * 30, midy + 15 + activey * 30, WHITE);
}

// Draw the outer rectangle for the Sudoku grid
rectangle(midx, midy, midx + 300, midy + 300);

// Wait for a key press
getch();

/* clean up */
}

// Wait for another key press before closing the graphics window
getch();

// Close the graphics window and clean up graphics resources
closegraph();

// Exit the program with a return value of 0 (indicating successful termination)
return 0;
}

