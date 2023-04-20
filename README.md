<h1>CP4 GROUP: Nicolas Said and Yin Hei (Jason) Chan</h1>

<h3>File Structure:</h3>

<ul>
    <li> Node.cpp and Node.h - Implementation of the Node Class</li>
    <li> BST.cpp and BST.h - Implementation of our integer BST Class</li>
    <li> main.cpp - Implementation of our experiments for testing out BST's effectiveness</li>
</ul>

<h3>Experiements Explained:</h3>

<p>For our experiments, we created many helper functions to test the effectiveness of different shaped BSTs. Using trees of different sizes, we have generated a tree that is skewed, a tree that is slightly randomized, and a tree that is heavily randomized for each time the test method was called. In this test method, we averaged the number of comparisons made for a number of random calls to functions find (executed n/2 times), insert (called 50 times), and delete (called 50 times) where n is the number of nodes. The reason why we only called insert and delete 50 times was to avoid altering the tree in a meaningful way during the tests. After recording the average number of comparisons, we recorded the average results for trees of different sizes to see how our results scale with the number of nodes</p>

<h3>How to Run:</h3>

<ul>
    <li> Execute the make file to generate executable called exec
    <li> Use ./exec to run the executable which has our basic experiments that we used on multiple runs to average
    <li> After execution is done, call make clean to remove the executable and any object files used for linking
</ul>

<h3>Data Recorded:</h3>

<b>Skew</b>

    Size of Tree | Average Comparisons Find | Average Comparisons Insert | Average Comparisons Remove
       50000                 24976                      28643                        28641

<b>Slightly Random</b>

    Size of Tree | Average Comparisons Find | Average Comparisons Insert | Average Comparisons Remove
       50000                 12217                      12343                        12343

<b>Fully Random</b>

    Size of Tree | Average Comparisons Find | Average Comparisons Insert | Average Comparisons Remove
       50000                 1394                       1249                         1249 

<b>Height and Depth Data</b>

    Average Height of Skewed Tree:             49949
    Average Depth of Skewed Tree:              24975

    Average Height of Slightly Random Tree:    18879
    Average Depth of Slightly Random Tree:      8682

    Average Height of Fully Random Tree:        7667
    Average Depth of Fully Random Tree:         1542


<b>Raw Data:</b>

    Round 1. Fight!
    Skewed
    Average comparisons for find: 24962
    Average comparisons for remove: 30022
    Average comparisons for insert: 30019
    Slightly Random
    Average comparisons for find: 9918
    Average comparisons for remove: 9691
    Average comparisons for insert: 9690
    Fully Random
    Average comparisons for find: 1021
    Average comparisons for remove: 994
    Average comparisons for insert: 994
    ------------------------------

    Round 2. Fight!
    Skewed
    Average comparisons for find: 25022
    Average comparisons for remove: 22086
    Average comparisons for insert: 22083
    Slightly Random
    Average comparisons for find: 12638
    Average comparisons for remove: 9854
    Average comparisons for insert: 9853
    Fully Random
    Average comparisons for find: 2128
    Average comparisons for remove: 2372
    Average comparisons for insert: 2372
    ------------------------------

    Round 3. Fight!
    Skewed
    Average comparisons for find: 24964
    Average comparisons for remove: 33852
    Average comparisons for insert: 33849
    Slightly Random
    Average comparisons for find: 12935
    Average comparisons for remove: 13215
    Average comparisons for insert: 13215
    Fully Random
    Average comparisons for find: 970
    Average comparisons for remove: 534
    Average comparisons for insert: 534
    ------------------------------

    Round 4. Fight!
    Skewed
    Average comparisons for find: 24878
    Average comparisons for remove: 27029
    Average comparisons for insert: 27028
    Slightly Random
    Average comparisons for find: 12712
    Average comparisons for remove: 14795
    Average comparisons for insert: 14795
    Fully Random
    Average comparisons for find: 1051
    Average comparisons for remove: 1047
    Average comparisons for insert: 1047
    ------------------------------

    Round 5. Fight!
    Skewed
    Average comparisons for find: 25058
    Average comparisons for remove: 30228
    Average comparisons for insert: 30226
    Slightly Random
    Average comparisons for find: 12884
    Average comparisons for remove: 14164
    Average comparisons for insert: 14164
    Fully Random
    Average comparisons for find: 1802
    Average comparisons for remove: 1301
    Average comparisons for insert: 1301
    ------------------------------


<b>Skew</b>

    Size of Tree | Average Comparisons Find | Average Comparisons Insert | Average Comparisons Remove
        10000                 4974                       5153                         5141

<b>Slightly Random</b>

    Size of Tree | Average Comparisons Find | Average Comparisons Insert | Average Comparisons Remove
        10000                 1664                       1539                         1535

<b>Fully Random</b>

    Size of Tree | Average Comparisons Find | Average Comparisons Insert | Average Comparisons Remove
        10000                  243                        229                          232

<b>Height and Depth Data</b>

    Average Height of Skewed Tree:              9949
    Average Depth of Skewed Tree:               4976
    
    Average Height of Slightly Random Tree:     4762
    Average Depth of Slightly Random:           2007
    
    Average Height of Fully Random Tree:        1330
    Average Depth of Fully Random Tree:          323

<b>Raw Data</b>

    Round 1. Fight!
    Skewed
    Average comparisons for find: 4974
    Average comparisons for remove: 5153
    Average comparisons for insert: 5141
    Slightly Random
    Average comparisons for find: 1467
    Average comparisons for remove: 1388
    Average comparisons for insert: 1384
    Fully Random
    Average comparisons for find: 375
    Average comparisons for remove: 368
    Average comparisons for insert: 380
    ------------------------------

    Round 2. Fight!
    Skewed
    Average comparisons for find: 4974
    Average comparisons for remove: 5153
    Average comparisons for insert: 5141
    Slightly Random
    Average comparisons for find: 1736
    Average comparisons for remove: 1640
    Average comparisons for insert: 1636
    Fully Random
    Average comparisons for find: 227
    Average comparisons for remove: 223
    Average comparisons for insert: 224
    ------------------------------

    Round 3. Fight!
    Skewed
    Average comparisons for find: 4974
    Average comparisons for remove: 5153
    Average comparisons for insert: 5141
    Slightly Random
    Average comparisons for find: 1656
    Average comparisons for remove: 1618
    Average comparisons for insert: 1613
    Fully Random
    Average comparisons for find: 165
    Average comparisons for remove: 142
    Average comparisons for insert: 142
    ------------------------------

    Round 4. Fight!
    Skewed
    Average comparisons for find: 4974
    Average comparisons for remove: 5153
    Average comparisons for insert: 5141
    Slightly Random
    Average comparisons for find: 1539
    Average comparisons for remove: 1261
    Average comparisons for insert: 1259
    Fully Random
    Average comparisons for find: 193
    Average comparisons for remove: 182
    Average comparisons for insert: 182
    ------------------------------

    Round 5. Fight!
    Skewed
    Average comparisons for find: 4974
    Average comparisons for remove: 5153
    Average comparisons for insert: 5141
    Slightly Random
    Average comparisons for find: 1923
    Average comparisons for remove: 1791
    Average comparisons for insert: 1785
    Fully Random
    Average comparisons for find: 259
    Average comparisons for remove: 232
    Average comparisons for insert: 232
    ------------------------------

<b>Skew</b>

    Size of Tree | Average Comparisons Find | Average Comparisons Insert | Average Comparisons Remove
        1000                 511                        436                          426
<b>Slightly Random</b>

    Size of Tree | Average Comparisons Find | Average Comparisons Insert | Average Comparisons Remove
        1000                  91                         84                           83

<b>Fully Random</b>

    Size of Tree | Average Comparisons Find | Average Comparisons Insert | Average Comparisons Remove
        1000                  18                         20                           21

<b>Height and Depth Data</b>

    Average Height of Skewed Tree:               950
    Average Depth of Skewed Tree:                472

    Average Height of Slightly Random Tree:      240
    Average Depth of Slightly Random Tree:       118

    Average Height of Fully Random Tree:          91
    Average Depth of Fully Random Tree:           22

<b>Raw Data:</b>

    Round 1. Fight!
    Skewed
    Average comparisons for find: 511
    Average comparisons for remove: 436
    Average comparisons for insert: 426
    Slightly Random
    Average comparisons for find: 55
    Average comparisons for remove: 55
    Average comparisons for insert: 55
    Fully Random
    Average comparisons for find: 15
    Average comparisons for remove: 19
    Average comparisons for insert: 20
    ------------------------------

    Round 2. Fight!
    Skewed
    Average comparisons for find: 511
    Average comparisons for remove: 436
    Average comparisons for insert: 426
    Slightly Random
    Average comparisons for find: 85
    Average comparisons for remove: 84
    Average comparisons for insert: 82
    Fully Random
    Average comparisons for find: 16
    Average comparisons for remove: 19
    Average comparisons for insert: 19
    ------------------------------

    Round 3. Fight!
    Skewed
    Average comparisons for find: 511
    Average comparisons for remove: 436
    Average comparisons for insert: 426
    Slightly Random
    Average comparisons for find: 86
    Average comparisons for remove: 73
    Average comparisons for insert: 71
    Fully Random
    Average comparisons for find: 15
    Average comparisons for remove: 15
    Average comparisons for insert: 16
    ------------------------------

    Round 4. Fight!
    Skewed
    Average comparisons for find: 511
    Average comparisons for remove: 436
    Average comparisons for insert: 426
    Slightly Random
    Average comparisons for find: 73
    Average comparisons for remove: 70
    Average comparisons for insert: 69
    Fully Random
    Average comparisons for find: 29
    Average comparisons for remove: 32
    Average comparisons for insert: 32
    ------------------------------

    Round 5. Fight!
    Skewed
    Average comparisons for find: 511
    Average comparisons for remove: 436
    Average comparisons for insert: 426
    Slightly Random
    Average comparisons for find: 159
    Average comparisons for remove: 141
    Average comparisons for insert: 139
    Fully Random
    Average comparisons for find: 17
    Average comparisons for remove: 19
    Average comparisons for insert: 20
    ------------------------------

<h2>Conclusions</h2>

<ul>
    <li> The number of comparisons grow much faster in a skew tree than a randomized tree. This is most likely because a skew tree's search is O(n) while a balanced tree's search is O(log(n))
    <li> The average number of comparisons for a skew tree versus a randomized tree of the same size varies by a wide margin. This is also most likely due to the big O time complexity based on the organization of the tree
    <li> The height and average depth also grow much slower in the randomized trees in comparison to the skewed trees because of the height and average depth in a skewed tree being O(n) and the height and average depth of a tree as it becomes closer to becoming balanced approached log(n)
</ul>
