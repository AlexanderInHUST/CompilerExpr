# CompilerExpr
A very basic compiler
## test.c
``` C
float b, c = 0, e = 5 + a++ / 2.5f;
while (a == 4) {
    char a = '3';
    char qw = '4';
}
char ss;
if (a == b + c) {
    while (sssss == 4) {
        e = b + qw;
    }
} else if (b == 3) {
    if (a == 4) {
        e = 2 + a;
    }
    b = 3.90f;
}
```
## Output for test.c
    |---[ float ]---[ , ]---[ , ]---[ b ]
                |---[ c= ]---[ 0 ]
            |---[ e= ]---[ + ]---[ 5 ]
                    |---[ / ]---[ a++ ]
                        |---[ 2.500000 ]
    |---[ while ]---[ == ]---[ a ]
            |---[ 4 ]
        Then:
        |---[ char ]---[ a= ]---[ 3 ]
        |---[ char ]---[ qw= ]---[ 4 ]
    |---[ char ]---[ ss ]
    |---[ if-else ]---[ == ]---[ a ]
            |---[ + ]---[ b ]
                |---[ c ]
        Then:
        |---[ while ]---[ == ]---[ sssss ]
                |---[ 4 ]
            Then:
            |---[ e= ]---[ + ]---[ b ]
                    |---[ qw ]
        Else:
        |---[ if ]---[ == ]---[ b ]
                |---[ 3 ]
            Then:
            |---[ if ]---[ == ]---[ a ]
                    |---[ 4 ]
                Then:
                |---[ e= ]---[ + ]---[ 2 ]
                        |---[ a ]
            |---[ b= ]---[ 3.900000 ]
    There exist 8 semantics errors!
    The 1 error:
        Undefined symbol happens at line 1 with keyword "a"
    The 2 error:
        Undefined symbol happens at line 2 with keyword "a"
    The 3 error:
        Undefined symbol happens at line 7 with keyword "a"
    The 4 error:
        Undefined symbol happens at line 8 with keyword "sssss"
    The 5 error:
        Undefined symbol happens at line 9 with keyword "qw"
    The 6 error:
        Undefined symbol happens at line 12 with keyword "a"
    The 7 error:
        Undefined symbol happens at line 13 with keyword "a"
    The 8 error:
        Type error happens at line 13 with keyword "e"

    Symbol table of 1
    |------------|--|------------|--|------------|
    |symbol_name |  |    type    |  |field_level |
    |------------|--|------------|--|------------|
    |b           |  |Float       |  |0           |
    |c           |  |Float       |  |0           |
    |e           |  |Float       |  |0           |
    |ss          |  |Character   |  |0           |
    |#_tmp_0     |  |Integer     |  |-1          |
    |#_tmp_1     |  |Float       |  |-1          |
    |#_tmp_2     |  |Float       |  |-1          |
    |#_tmp_3     |  |Integer     |  |-1          |
    |#_tmp_4     |  |Float       |  |-1          |
    |#_tmp_5     |  |Float       |  |-1          |
    |#_tmp_6     |  |Float       |  |-1          |
    |------------|--|------------|--|------------|

    Symbol table of 1-1
    |------------|--|------------|--|------------|
    |symbol_name |  |    type    |  |field_level |
    |------------|--|------------|--|------------|
    |b           |  |Float       |  |0           |
    |c           |  |Float       |  |0           |
    |e           |  |Float       |  |0           |
    |a           |  |Character   |  |1           |
    |qw          |  |Character   |  |1           |
    |------------|--|------------|--|------------|

    Symbol table of 1-2
    |------------|--|------------|--|------------|
    |symbol_name |  |    type    |  |field_level |
    |------------|--|------------|--|------------|
    |b           |  |Float       |  |0           |
    |c           |  |Float       |  |0           |
    |e           |  |Float       |  |0           |
    |ss          |  |Character   |  |0           |
    |#_tmp_0     |  |Integer     |  |-1          |
    |------------|--|------------|--|------------|

    Symbol table of 1-2-1
    |------------|--|------------|--|------------|
    |symbol_name |  |    type    |  |field_level |
    |------------|--|------------|--|------------|
    |b           |  |Float       |  |0           |
    |c           |  |Float       |  |0           |
    |e           |  |Float       |  |0           |
    |ss          |  |Character   |  |0           |
    |#_tmp_0     |  |Float       |  |-1          |
    |------------|--|------------|--|------------|

    Symbol table of 1-3
    |------------|--|------------|--|------------|
    |symbol_name |  |    type    |  |field_level |
    |------------|--|------------|--|------------|
    |b           |  |Float       |  |0           |
    |c           |  |Float       |  |0           |
    |e           |  |Float       |  |0           |
    |ss          |  |Character   |  |0           |
    |#_tmp_0     |  |Integer     |  |-1          |
    |------------|--|------------|--|------------|

    Symbol table of 1-3-1
    |------------|--|------------|--|------------|
    |symbol_name |  |    type    |  |field_level |
    |------------|--|------------|--|------------|
    |b           |  |Float       |  |0           |
    |c           |  |Float       |  |0           |
    |e           |  |Float       |  |0           |
    |ss          |  |Character   |  |0           |
    |#_tmp_0     |  |Integer     |  |-1          |
    |------------|--|------------|--|------------|
    The TAC codes are below:
    (=, , 0, c)
    (+, a, 0, #_tmp_0)
    (/, #_tmp_0, 2.500000, #_tmp_1)
    (+, 5, #_tmp_1, #_tmp_2)
    (=, , #_tmp_2, e)
    (+, a, 1, a)
    @_label_1:
    (==, a, 4, #_tmp_3)
    (jne, 0, #_tmp_3, @_label_0)
    {:
    (=, , '3', a)
    (=, , '4', qw)
    }:
    (jmp, , , @_label_1)
    @_label_0:
    (+, b, c, #_tmp_4)
    (==, a, #_tmp_4, #_tmp_5)
    (jne, 0, #_tmp_5, @_label_7)
    {:
    @_label_3:
    (==, sssss, 4, #_tmp_0)
    (jne, 0, #_tmp_0, @_label_2)
    {:
    (+, b, qw, #_tmp_0)
    (=, , #_tmp_0, e)
    }:
    (jmp, , , @_label_3)
    @_label_2:
    }:
    (jmp, , , @_label_6)
    @_label_7:
    (==, b, 3, #_tmp_6)
    (jne, 0, #_tmp_6, @_label_5)
    {:
    (==, a, 4, #_tmp_0)
    (jne, 0, #_tmp_0, @_label_4)
    {:
    (+, 2, a, #_tmp_0)
    (=, , #_tmp_0, e)
    }:
    @_label_4:
    (=, , 3.900000, b)
    }:
    @_label_5:
    @_label_6: