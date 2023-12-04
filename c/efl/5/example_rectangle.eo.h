#ifndef _EXAMPLE_RECTANGLE_EO_H_
#define _EXAMPLE_RECTANGLE_EO_H_

#ifndef _EXAMPLE_RECTANGLE_EO_CLASS_TYPE
#define _EXAMPLE_RECTANGLE_EO_CLASS_TYPE

typedef Eo Example_Rectangle;

#endif

#ifndef _EXAMPLE_RECTANGLE_EO_TYPES
#define _EXAMPLE_RECTANGLE_EO_TYPES


#endif
#define EXAMPLE_RECTANGLE_CLASS example_rectangle_class_get()

EAPI EAPI_WEAK const Efl_Class *example_rectangle_class_get(void) EINA_CONST;

EAPI EAPI_WEAK void example_rectangle_width_set(Eo *obj, int width);

EAPI EAPI_WEAK int example_rectangle_width_get(const Eo *obj);

EAPI EAPI_WEAK void example_rectangle_height_set(Eo *obj, int height);

EAPI EAPI_WEAK int example_rectangle_height_get(const Eo *obj);

EAPI EAPI_WEAK int example_rectangle_area(Eo *obj);

#endif
