#include "body.h"

void Body::SetHitbox(float x, float y, int width, int height)
{
    hitbox.x = x;
    hitbox.y = y;
    hitbox.width = float(width);
    hitbox.height = float(height);
}

void Body::CheckPlatformTileCollision(Grid *grid, Vector2 *velocity, int tileWidth, int tileHeight)
{
    bool collision = true;
    int tx = 0;
    int tx1 = 0;
    int tx2 = 0;
    int ty = 0;
    int ty1 = 0;
    int ty2 = 0;
    float amount = 0;

    if (velocity->x != 0)
    {
        // x part

        if (velocity->x < 0)
        {
            tx = int((pos.x + velocity->x) / tileWidth);
            amount = 0.1F;
        }
        else
        {
            tx = int(((pos.x + 15) + velocity->x) / tileWidth);
            amount = -0.1F;
        }

        ty1 = int(pos.y / tileHeight);
        ty2 = int((pos.y + 15) / tileHeight);

        while (collision)
        {
            if (grid->GetTile(tx, ty1) || grid->GetTile(tx, ty2))
            {
                velocity->x += amount;

                if (velocity->x < 0)
                    tx = int((pos.x + velocity->x) / tileWidth);
                else
                    tx = int(((pos.x + 15) + velocity->x) / tileWidth);
            }
            else
                collision = false;
        }

        pos.x += velocity->x;
    }

    // y part

    if (velocity->y < 0)
    {
        ty = int((pos.y + velocity->y) / tileHeight);
        amount = 0.1F;
    }
    else
    {
        ty = int(((pos.y + 15) + velocity->y) / tileHeight);
        amount = -0.1F;
    }

    tx1 = int(pos.x / tileWidth);
    tx2 = int((pos.x + 15) / tileWidth);

    collision = true;
    bool groundCollision = false;

    while (collision)
    {
        if (grid->GetTile(tx1, ty) || grid->GetTile(tx2, ty))
        {
            velocity->y += amount;

            if (velocity->y < 0)
                ty = int((pos.y + velocity->y) / tileHeight);
            else
            {
                ty = int(((pos.y + 15) + velocity->y) / tileHeight);
                og = true;
                groundCollision = true;
            }
        }
        else
            collision = false;
    }

    if (!groundCollision)
        og = false;

    pos.y += velocity->y;
}