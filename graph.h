char zero[5][3] = {{' ', '-', ' '},
                   {'|', ' ', '|'},
                   {' ', ' ', ' '},
                   {'|', ' ', '|'},
                   {' ', '-', ' '}};

char one[5][3] = {{' ', ' ', ' '},
                  {' ', ' ', '|'},
                  {' ', ' ', ' '},
                  {' ', ' ', '|'},
                  {' ', ' ', ' '}};

char two[5][3] = {{' ', '-', ' '},
                  {' ', ' ', '|'},
                  {' ', '-', ' '},
                  {'|', ' ', ' '},
                  {' ', '-', ' '}};

char three[5][3] = {{' ', '-', ' '},
                    {' ', ' ', '|'},
                    {' ', '-', ' '},
                    {' ', ' ', '|'},
                    {' ', '-', ' '}};

char four[5][3] = {{' ', ' ', ' '},
                   {'|', ' ', '|'},
                   {' ', '-', ' '},
                   {' ', ' ', '|'},
                   {' ', ' ', ' '}};

char five[5][3] = {{' ', '-', ' '},
                   {'|', ' ', ' '},
                   {' ', '-', ' '},
                   {' ', ' ', '|'},
                   {' ', '-', ' '}};

char six[5][3] = {{' ', '-', ' '},
                  {'|', ' ', ' '},
                  {' ', '-', ' '},
                  {'|', ' ', '|'},
                  {' ', '-', ' '}};

char seven[5][3] = {{' ', '-', ' '},
                    {' ', ' ', '|'},
                    {' ', ' ', ' '},
                    {' ', ' ', '|'},
                    {' ', ' ', ' '}};

char eight[5][3] = {{' ', '-', ' '},
                    {'|', ' ', '|'},
                    {' ', '-', ' '},
                    {'|', ' ', '|'},
                    {' ', '-', ' '}};

char nine[5][3] = {{' ', '-', ' '},
                   {'|', ' ', '|'},
                   {' ', '-', ' '},
                   {' ', ' ', '|'},
                   {' ', '-', ' '}};

char error[5][3] = {{' ', '-', ' '},
                    {'|', ' ', ' '},
                    {' ', '-', ' '},
                    {'|', ' ', ' '},
                    {' ', '-', ' '}};

typedef char graph_arr[5][3];
graph_arr *graphs[70] = {['0'] = &zero,
                         ['1'] = &one,
                         ['2'] = &two,
                         ['3'] = &three,
                         ['4'] = &four,
                         ['5'] = &five,
                         ['6'] = &six,
                         ['7'] = &seven,
                         ['8'] = &eight,
                         ['9'] = &nine,
                         ['E'] = &error};
