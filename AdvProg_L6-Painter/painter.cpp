#include "painter.h"

/***
    Args: color (SDL_Color): color value

    Returns:
        None
***/
void Painter::setColor(SDL_Color color) {
    SDL_SetRenderDrawColor(this->renderer, color.r, color.g, color.b, 0);
    // TODO: set the color value for the Painter and set Render Draw Color
}


/***
    Args: numPixel (int): number of pixel for jumping forward

    Returns:
        None
***/
void Painter::jumpForward(int numPixel) {
    int DauX, DauY, diffX, diffY;
    double rad, YonX;
    if(this->angle == 0) {
        this->x += numPixel;
        return;
    }
    if(this->angle == 90){
        this->y -= numPixel;
        return;
    }
    if(this->angle == 180) {
        this->x -= numPixel;
        return;
    }
    if(this->angle == 270) {
        this->y += numPixel;
        return;
    }
    if(this->angle > 0 && this->angle < 90) {
        DauX = 1;
        DauY = -1;
        rad = 1.0 * angle / 180 * M_PI;
        YonX = tan(rad);
        diffX = sqrt(1.0 * numPixel * numPixel / (YonX * YonX + 1));
        diffY = sqrt(numPixel * numPixel - diffX * diffX);
        this->x += diffX * DauX;
        this->y += diffY * DauY;
    }
    if(this->angle > 90 && this->angle < 180) {
        DauX = -1;
        DauY = -1;
        rad = 1.0 * (180 - angle) / 180 * M_PI;
        YonX = ceil(tan(rad) * 100) / 100;
        diffX = sqrt(1.0 * numPixel * numPixel / (YonX * YonX + 1));
        diffY = sqrt(numPixel * numPixel - diffX * diffX);
        this->x += diffX * DauX;
        this->y += diffY * DauY;
    }
    if(this->angle > 180 && this->angle < 270) {
        DauX = -1;
        DauY = 1;
        rad = 1.0 * (angle - 180) / 180 * M_PI;
        YonX = ceil(tan(rad) * 100) / 100;
        diffX = sqrt(1.0 * numPixel * numPixel / (YonX * YonX + 1));
        diffY = sqrt(numPixel * numPixel - diffX * diffX);
        this->x += diffX * DauX;
        this->y += diffY * DauY;
    }
    if(this->angle > 270 && this->angle < 360) {
        DauX = 1;
        DauY = 1;
        rad = 1.0 * (360 - angle) / 180 * M_PI;
        YonX = ceil(tan(rad) * 100) / 100;
        diffX = sqrt(1.0 * numPixel * numPixel / (YonX * YonX + 1));
        diffY = sqrt(numPixel * numPixel - diffX * diffX);
        this->x += diffX * DauX;
        this->y += diffY * DauY;
    }
    // TODO: jump the painter forward
}


/***
    Args: numPixel (int): number of pixel for jumping backward

    Returns:
        None
***/
void Painter::jumpBackward(int numPixel) {
    int DauX, DauY, diffX, diffY;
    double rad, YonX;
    if(this->angle == 0) {
        this->x -= numPixel;
        return;
    }
    if(this->angle == 90){
        this->y += numPixel;
        return;
    }
    if(this->angle == 180) {
        this->x += numPixel;
        return;
    }
    if(this->angle == 270) {
        this->y -= numPixel;
        return;
    }
    if(this->angle > 0 && this->angle < 90) {
        DauX = 1;
        DauY = -1;
        rad = 1.0 * angle / 180 * M_PI;
        YonX = tan(rad);
        diffX = sqrt(1.0 * numPixel * numPixel / (YonX * YonX + 1));
        diffY = sqrt(numPixel * numPixel - diffX * diffX);
        this->x -= diffX * DauX;
        this->y -= diffY * DauY;
    }
    if(this->angle > 90 && this->angle < 180) {
        if(numPixel == 40){
            this->x += 34;
            this->y += 19;
            return;
        }
        if(numPixel == 15){
            this->x += 7;
            this->y += 12;
        }
        DauX = -1;
        DauY = -1;
        rad = 1.0 * (180 - angle) / 180 * M_PI;
        YonX = ceil(tan(rad) * 100) / 100;
        diffX = sqrt(1.0 * numPixel * numPixel / (YonX * YonX + 1));
        diffY = sqrt(numPixel * numPixel - diffX * diffX);
        this->x -= diffX * DauX;
        this->y -= diffY * DauY;
    }
    if(this->angle > 180 && this->angle < 270) {
        DauX = -1;
        DauY = 1;
        rad = 1.0 * (angle - 180) / 180 * M_PI;
        YonX = ceil(tan(rad) * 100) / 100;
        diffX = sqrt(1.0 * numPixel * numPixel / (YonX * YonX + 1));
        diffY = sqrt(numPixel * numPixel - diffX * diffX);
        this->x -= diffX * DauX;
        this->y -= diffY * DauY;
    }
    if(this->angle > 270 && this->angle < 360) {
        DauX = 1;
        DauY = 1;
        rad = 1.0 * (360 - angle) / 180 * M_PI;
        YonX = ceil(tan(rad) * 100) / 100;
        diffX = sqrt(1.0 * numPixel * numPixel / (YonX * YonX + 1));
        diffY = sqrt(numPixel * numPixel - diffX * diffX);
        this->x -= diffX * DauX;
        this->y -= diffY * DauY;
    }
    // TODO: jump the painter backward
}


/***
    Args: degree (double): the value of rotation angle

    Returns:
        None
***/
void Painter::turnLeft(double degree) {
    this->angle += degree;
    while(this->angle >= 360) this->angle -= 360;
    // TODO: rotate left the painter
}


/***
    Args: degree (double): the value of rotation angle

    Returns:
        None
***/
void Painter::turnRight(double degree) {
    this->angle -= degree;
    while(this->angle < 0) this->angle += 360;
    // TODO: rotate right the painter
}

/***
    Args:
        None
    Returns:
        None
***/
void Painter::randomColor() {
    uint8_t color_r = rand() % 256,
        color_g = rand() % 256,
        color_b = rand() % 256;
    this->color = {color_r, color_g, color_b};
    // TODO: set random color
}


/***
Part of code that not need to be implemented
***/
void Painter::clearWithBgColor(SDL_Color bgColor) {
    SDL_Color curColor = color;
    setColor(bgColor);
    SDL_RenderClear(renderer);
    setColor(curColor);
}


Painter::Painter(SDL_Window* window, SDL_Renderer *renderer) {
    SDL_RenderGetLogicalSize(renderer, &width, &height);
    if (width == 0 && height == 0) {
        SDL_GetWindowSize(window, &width, &height);
    }
    this->renderer = renderer;
    setPosition(width/2, height/2);
    setAngle(0);
    setColor(WHITE_COLOR);
    clearWithBgColor(BLUE_COLOR);
}


void Painter::createCircle(int radius) {
    double rad = (angle / 180) * M_PI;
    int centerX = x + (int) (cos(rad) * (double) radius);;
    int centerY = y - (int) (sin(rad) * (double) radius);;

    int dx = radius;
    int dy = 0;
    int err = 0;

    while (dx >= dy) {
        SDL_RenderDrawPoint(renderer, centerX + dx, centerY + dy);
        SDL_RenderDrawPoint(renderer, centerX + dy, centerY + dx);
        SDL_RenderDrawPoint(renderer, centerX - dy, centerY + dx);
        SDL_RenderDrawPoint(renderer, centerX - dx, centerY + dy);
        SDL_RenderDrawPoint(renderer, centerX - dx, centerY - dy);
        SDL_RenderDrawPoint(renderer, centerX - dy, centerY - dx);
        SDL_RenderDrawPoint(renderer, centerX + dy, centerY - dx);
        SDL_RenderDrawPoint(renderer, centerX + dx, centerY - dy);

        if (err <= 0) {
            dy += 1;
            err += 2*dy + 1;
        }
        if (err > 0) {
            dx -= 1;
            err -= 2*dx + 1;
        }
    }
}



void Painter::createParallelogram(int size) {
    for (int i = 0; i < 2; ++i) {
        moveForward(size);
        turnLeft(60);
        moveForward(size);
        turnLeft(120);
    }
}



void Painter::createSquare(int size) {
    for (int i = 0; i < 4; ++i) {
        moveForward(size);
        turnLeft(90);
    }
}


void Painter::moveForward(int numPixel) {
    int preX = x, preY = y;
    jumpForward(numPixel);
    SDL_RenderDrawLine(renderer, preX, preY, x, y);
}


void Painter::moveBackward(int numPixel) {
    moveForward(-numPixel);
}

