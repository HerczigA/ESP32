/*
Done! You can now compile ESP-IDF projects.
Go to the project directory and run:
idf.py build

start->esp-> cd dir -> idf.py build -> flash

*/
#include <esp_intr_alloc.h>
// int ISR_num = 0;
esp_intr_enable(ISR_num);


int main(int argc, char *argv[])
{
    // esp_sleep_start();
    return 0;
}