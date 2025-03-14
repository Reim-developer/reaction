#ifndef PANEL_H
#define PANEL_H
#include <gtk/gtk.h>


typedef struct {
    GtkWidget *panel_area_t;
    int width;
    int height;
    int grid_column;
    int grid_row;
    int grid_width;
    int grid_height;
} panel_t;

panel_t * result_panel_widget_new(void);

#endif // PANEL_H 
