#ifndef LABEL_H
#define LABEL_H
#include <gtk/gtk.h>

typedef struct {
    GtkWidget *label;
    int width;
    int height;
    int grid_column;
    int grid_row;
    int grid_width;
    int grid_height;
} label_t;

label_t *label_description_new(void);

#endif // LABEL_H
