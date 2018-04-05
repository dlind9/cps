#include "../headers/shape.h"


void Shape::scale(Scale s) {
     transformation += s.postscript();
}

void Shape::translate(Translation t) {
     transformation += t.postscript();
}

void Shape::rotate(Rotation r) {
    transformation += r.postscript();
}
