
eolian_gen -gchi example_rectangle.eo

gcc -o eo-classes eo_classes_main.c example_rectangle.c `pkg-config --cflags --libs eina efl elementary`
