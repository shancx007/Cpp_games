%:
	%:
	g++ $@.cpp -o $@ -lraylib -lglfw3 -lopengl32 -lgdi32 -lwinmm
	./$@.exe
	