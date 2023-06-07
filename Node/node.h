#ifndef NODE_H
#define NODE_H

#include <QRect>
#include <QList>
#include "../Path/path.h"

namespace find_path {
    class Node {
    private:
        uint value;
        bool enabled;
        QList<Node*> edges;

        QRectF rect;

        static uint count;
    protected:
    public:
        explicit Node(bool flag = false);
        explicit Node(const QRectF& rect, bool flag = false);
        Node(int x, int y, int width, int height, bool flag = false);
        Node(const Node& node);
        Node(Node&& node);
        virtual ~Node();

        Node& operator=(const Node& node);
        Node& operator=(Node&& node);

        const bool IsEnabled() const;
        void SetEnabled(const bool flag);

        const QRectF& GetRect() const;
        void SetRect(const QRectF& rect);

        const bool HasEdge(const Node& to) const;
        const QList<Node*>& RelatedEdges() const;



        void AddEdge(Node* to);
        void RemoveEdge(Node* to);
    };
}

#endif // NODE_H
