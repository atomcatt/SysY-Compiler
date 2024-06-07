make clean
make
./parser < ./tests/1/1-array.c > ./results/1/1-array
./parser < ./tests/2/2-comment.c > ./results/2/2-comment
./parser < ./tests/3/3-globalvar.c > ./results/3/3-globalvar
./parser < ./tests/4/4-exgcd.c > ./results/4/4-exgcd
./parser < ./tests/5/5-kmp.c > ./results/5/5-kmp
./parser < ./tests/6/6-substr.c > ./results/6/6-substr
./parser < ./tests/7/7-side_effect.c > ./results/7/7-side_effect
./parser < ./tests/8/8-long_array.c > ./results/8/8-long_array
./parser < ./tests/9/9-many_params.c > ./results/9/9-many_params
./parser < ./tests/10/10-many_locals.c > ./results/10/10-many_locals
python3 tree.py ./results/1/1-array ./results/1/1-array.dot
python3 tree.py ./results/2/2-comment ./results/2/2-comment.dot
python3 tree.py ./results/3/3-globalvar ./results/3/3-globalvar.dot
python3 tree.py ./results/4/4-exgcd ./results/4/4-exgcd.dot
python3 tree.py ./results/5/5-kmp ./results/5/5-kmp.dot
python3 tree.py ./results/6/6-substr ./results/6/6-substr.dot
python3 tree.py ./results/7/7-side_effect ./results/7/7-side_effect.dot
python3 tree.py ./results/8/8-long_array ./results/8/8-long_array.dot
python3 tree.py ./results/9/9-many_params ./results/9/9-many_params.dot
python3 tree.py ./results/10/10-many_locals ./results/10/10-many_locals.dot
