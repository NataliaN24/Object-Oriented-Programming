#include"Award.h"
#include"Penguin.h"
#include"Pacman.h"

int main() {
    Award* rewards[] = {
        new Penguin(10),
        new Pacman(20),

    };

    for (int i = 0; i < 5; ++i) {
        rewards[i]->visualize();
        delete rewards[i];
    }

    return 0;
}