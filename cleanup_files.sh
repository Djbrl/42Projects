find . -type f -name  "*.o" -exec rm -f {} \;
find . -type f -name  "*.swp" -exec rm -f {} \;
find . -type f -name  "a.out" -exec rm -f {} \;
find . -type f -name  "*.a" -exec rm -f {} \;
find . -type f -name  "*.he" -exec rm -f {} \;

git add *
git commit -m "[$1]"
git push
