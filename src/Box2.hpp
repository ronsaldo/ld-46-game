#ifndef BOX2_HPP
#define BOX2_HPP

#include "Vector2.hpp"

class Box2F
{
public:
    Box2F() = default;

    Box2F(const Vector2F &cmin, const Vector2F &cmax)
        : min(cmin), max(cmax) {}

    static Box2F empty()
    {
        return Box2F(Vector2F::infinity(), Vector2F::negativeInfinity());
    }

    static Box2F withMinAndMax(const Vector2F &cmin, const Vector2F &cmax)
    {
        return Box2F(cmin, cmax);
    }

    static Box2F withMinAndExtent(const Vector2F &cmin, const Vector2F &extent)
    {
        return Box2F(cmin, cmin + extent);
    }

    static Box2F withCenterAndHalfExtent(const Vector2F &center, const Vector2F &halfExtent)
    {
        return Box2F(center - halfExtent, center + halfExtent);
    }

    static Box2F withCenterAndExtent(const Vector2F &center, const Vector2F &halfExtent)
    {
        return withCenterAndHalfExtent(center, halfExtent / 2);
    }

    bool isEmpty() const
    {
        return min.x >= max.x || min.y >= max.y;
    }

    bool containsPoint(const Vector2F &p) const
    {
        return min.x <= p.x && p.x <= max.x &&
            min.y <= p.y && p.y <= max.y;
    }

    bool containsPointStrictly(const Vector2F &p) const
    {
        return min.x <= p.x && p.x < max.x &&
            min.y <= p.y && p.y < max.y;
    }

    bool isBoxOutside(const Box2F &other) const
    {
        return other.max.x < min.x || other.min.x > max.x ||
            other.max.y < min.y || other.min.y > max.y;
    }

    bool intersectsWithBox(const Box2F &other) const
    {
        return !isBoxOutside(other);
    }

    Vector2F extent() const
    {
        return max - min;
    }

    Vector2F halfExtent() const
    {
        return extent() / 2;
    }

    Vector2F center() const
    {
        return min + halfExtent();
    }

    Box2F translatedBy(const Vector2F &v) const
    {
        return Box2F(min + v, max + v);
    }

    Vector2F min;
    Vector2F max;
};

class Box2I
{
public:
    Box2I() = default;

    Box2I(const Vector2I &cmin, const Vector2I &cmax)
        : min(cmin), max(cmax) {}

    static Box2I withMinAndMax(const Vector2I &cmin, const Vector2I &cmax)
    {
        return Box2I(cmin, cmax);
    }

    static Box2I withMinAndExtent(const Vector2I &cmin, const Vector2I &extent)
    {
        return Box2I(cmin, cmin + extent);
    }

    static Box2I withCenterAndHalfExtent(const Vector2I &center, const Vector2I &halfExtent)
    {
        return Box2I(center - halfExtent, center + halfExtent);
    }

    static Box2I withCenterAndExtent(const Vector2I &center, const Vector2I &halfExtent)
    {
        return withCenterAndHalfExtent(center, halfExtent / 2);
    }

    bool isEmpty() const
    {
        return min.x >= max.x || min.y >= max.y;
    }

    bool containsPoint(const Vector2I &p) const
    {
        return min.x <= p.x && p.x <= max.x &&
            min.y <= p.y && p.y <= max.y;
    }

    bool containsPointStrictly(const Vector2I &p) const
    {
        return min.x <= p.x && p.x < max.x &&
            min.y <= p.y && p.y < max.y;
    }

    bool isBoxOutside(const Box2I &other) const
    {
        return other.max.x < min.x || other.min.x > max.x ||
            other.max.y < min.y || other.min.y > max.y;
    }

    bool intersectsWithBox(const Box2I &other) const
    {
        return !isBoxOutside(other);
    }

    Box2I intersectionWithBox(const Box2I &other) const
    {
        return Box2I(std::max(min, other.min), std::min(max, other.max));
    }

    Vector2I extent() const
    {
        return max - min;
    }

    Vector2I halfExtent() const
    {
        return extent() / 2;
    }

    Vector2I center() const
    {
        return min + halfExtent();
    }

    Box2I translatedBy(const Vector2I &v) const
    {
        return Box2I(min + v, max + v);
    }

    Vector2I min;
    Vector2I max;
};

#endif //BOX2_HPP
