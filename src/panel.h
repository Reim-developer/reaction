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

// Create new text_view_panel widget.
panel_t *result_panel_widget_new(void);
// Append text to text_view_panel widget.
void result_text_append_new(panel_t *panel_text_t, const char *content);
// Clear text in text_view_panel widget.
void result_text_clear_new(panel_t *panel_text_t);

#endif // PANEL_H 
