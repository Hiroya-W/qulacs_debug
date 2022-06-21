CC := g++
# TODO: remove `--coverage` fixing #339
CFLAGS := -O2 -g -fopenmp --coverage
INCLUDE := -I/workspaces/qulacs-osaka/include
LIBS := -L/workspaces/qulacs-osaka/lib
LDFLAGS := -lcppsim_static -lcsim_static -lvqcsim_static

main: main.cpp
	$(CC) $^ $(CFLAGS) $(INCLUDE) $(LIBS) $(LDFLAGS) -o $@

.PHONY: clean
clean:
	-rm main
	-rm *.gcda *.gcno
