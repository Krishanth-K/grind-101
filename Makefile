remove_exes:
	find . -path ./.git -prune -o -type f -executable -exec rm -f {} +

view_exes:
	find . -path ./.git -prune -o -type f -executable -print

