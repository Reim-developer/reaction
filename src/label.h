#ifndef LABEL_H
#define LABEL_H
#include <gtk/gtk.h>

typedef struct {
    GtkWidget *label;
    unsigned int width;
    unsigned int height;
    unsigned int grid_column;
    unsigned int grid_row;
    unsigned int grid_width;
    unsigned int grid_height;
} label_t;

label_t *label_description_new();

#endif // LABEL_H 