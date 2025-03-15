#ifndef PANEL_H
#define PANEL_H
#define IS_DEFAULT_TEXT_VIEW 1
#define DEFAULT_TEXT_CONTENT "Nothing to show..\n"
#define IS_NOT_DEFAULT_TEXT_VIEW 0
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
// Check text in text_view_panel widget.
int is_default_text_view(panel_t *panel_text_t, const char *match);

#endif // PANEL_H 
