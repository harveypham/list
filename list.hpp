#pragma once

#include <cstddef>

template<typename _Data>
class List {
public:
    typedef _Data value_type;
    typedef _Data & reference;
    typedef const _Data & const_reference;

private:
    class Node
    {
    public:
        value_type data;
        Node *prev;
        Node *next;
        template<typename ...Args>
        Node(Args ... args) : data(args...), prev(nullptr), next(nullptr) {}
    };

    Node *_head;
    Node *_tail;
    size_t _size;

    template<typename _move_trait>
    class _iterator_base {
    private:
        _iterator_base(Node *node) : _node(node) {}
        Node *_node;
        _move_trait move;
        friend class List<value_type>;

    public:
        value_type& operator *() { return _node->data; }
        value_type* operator->() { return &(_node->data); }
        bool operator==(const _iterator_base &other) const { return _node == other._node; }
        bool operator!=(const _iterator_base &other) const { return _node != other._node; }
        _iterator_base operator++() {
            _node = move.forward(_node);
            return *this;
        }
        _iterator_base operator++(int) {
            Node *current = _node;
            _node = move.forward(_node);
            return _iterator_base(current);
        }

        _iterator_base operator--() {
            _node = move.backward(_node);
            return *this;
        }

        _iterator_base operator--(int) {
            Node *current = _node;
            _node = move.backward(_node);
            return _iterator_base(current);
        }
    };

public:

    List(): _head(nullptr), _tail(nullptr), _size(0) {}

    ~List() {
        while (!empty()) {
            pop_front();
        }
    }

    size_t size() const {
        return _size;
    }

    bool empty() const {
        return _size == 0;
    }

    void push_front(const value_type &data) {
        Node * node = new Node(data);
        if (_head == nullptr) {
            _tail = node;
        }
        else {
            node->next = _head;
            _head->prev = node;
        }
        _head = node;
        ++_size;
    }

    void pop_front() {
        Node *front = _head;
        _head = front->next;
        front->next = nullptr;
        delete front;
        --_size;
        if (_head == nullptr) {
            _tail = nullptr;
        }
    }

    void push_back(const value_type &data) {
        Node *node = new Node(data);
        if (_tail == nullptr) {
            _head = node;
        } else {
            node->prev = _tail;
            _tail->next = node;
        }
        _tail = node;
        ++_size;
    }

    void pop_back() {
        Node *back = _tail;
        _tail = back->prev;
        back->prev = nullptr;
        delete back;
        --_size;
        if (_tail == nullptr) {
            _head = nullptr;
        }
    }

    reference front() {
        return _head->data;
    }

    const_reference front() const {
        return _head->data;
    }

    reference back() {
        return _tail->data;
    }

    const_reference back() const {
        return _tail->data;
    }

    struct to_tail {
        Node* forward(Node *node) { return node->next; }
        Node* backward(Node *node) { return node->prev; }
    };

    struct to_head {
        Node* forward(Node *node) { return node->prev; }
        Node* backward(Node *node) { return node->next; }
    };

    typedef _iterator_base<to_tail> iterator;
    typedef _iterator_base<to_head> reverse_iterator;

    iterator begin() {
        return iterator(_head);
    }

    iterator end() {
        return iterator(nullptr);
    }

    reverse_iterator rbegin() {
        return reverse_iterator(_tail);
    }

    reverse_iterator rend() {
        return reverse_iterator(nullptr);
    }

    void insert(const value_type& data, iterator pos) {
        if (pos == end()) {
            push_back(data);
        }
        else if (pos == begin()) {
            push_front(data);
        }
        else {
            Node *node = new Node(data);
            node->prev = pos._node->prev;
            node->prev->next = node;
            node->next = pos._node;
            pos._node->prev = node;
        }
    }

    void insert(const value_type& data, reverse_iterator pos) {
        if (pos == rbegin()) {
            push_back(data);
        }
        else if (pos == rend()) {
            push_front(data);
        } else {
            Node *node = new Node(data);
            node->next = pos._node->next;
            node->next->prev = node;
            node->prev = pos._node;
            pos._node->next = node;
        }
    }

};