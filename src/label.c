#include "label.h"

label_t *label_description_new() {
    label_t *label_description_top = g_new(label_t, 1);
    label_description_top->label = gtk_label_new(NULL);
    label_description_top->width = 10;
    label_description_top->height = 20;
    label_description_top->grid_column = 2;
    label_description_top->grid_row = 2;
    label_description_top->grid_width = 2;
    label_description_top->grid_height = 2;

    gtk_label_set_markup(GTK_LABEL(label_description_top->label), "<big> Drive Properties </big>");

    gtk_widget_set_size_request(label_description_top->label, label_description_top->width, label_description_top->height);

    return label_description_top;
}   