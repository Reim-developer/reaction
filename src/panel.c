#include "panel.h"

panel_t *result_panel_widget_new(void) {
    panel_t *scroll_widget_t = g_new(panel_t, 1);
    scroll_widget_t->panel_area_t = gtk_scrolled_window_new();
    GtkWidget *text_view_t = gtk_text_view_new();
    GtkTextBuffer *text_buffer_t = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view_t));

    gtk_widget_set_hexpand(scroll_widget_t->panel_area_t, TRUE);
    gtk_widget_set_vexpand(scroll_widget_t->panel_area_t, TRUE);
    gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scroll_widget_t->panel_area_t), text_view_t);
    gtk_text_buffer_set_text(text_buffer_t, "- Nothing to show..", -1);
    gtk_text_view_set_editable(GTK_TEXT_VIEW(text_view_t), FALSE);

    scroll_widget_t->width = 20;
    scroll_widget_t->height = 1;

    scroll_widget_t->grid_column = 15;
    scroll_widget_t->grid_row = 10;

    scroll_widget_t->grid_width = 20;
    scroll_widget_t->grid_height = 1;

    gtk_widget_set_size_request(scroll_widget_t->panel_area_t, scroll_widget_t->width, scroll_widget_t->height);
    return scroll_widget_t;
}
