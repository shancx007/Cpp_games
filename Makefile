%:
	g++ $@.cpp -o $@.exe -lraylib -lglfw3 -lopengl32 -lgdi32 -lwinmm
	./$@.exe