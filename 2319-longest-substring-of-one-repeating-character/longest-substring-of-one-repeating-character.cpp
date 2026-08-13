class Solution {
public:

    class Node {
    public:
        int l;      // maximum repeating substring
        int prl;    // prefix length
        int sfl;    // suffix length
        int len;    // segment length
        char s;     // first character
        char en;    // last character

        Node() {}

        Node(int l, int prl, int sfl, int len, char s, char en) {
            this->l = l;
            this->prl = prl;
            this->sfl = sfl;
            this->len = len;
            this->s = s;
            this->en = en;
        }
    };

    Node segm[400005];

    Node merge(Node lt, Node rt) {

        Node res;

        res.len = lt.len + rt.len;
        res.s = lt.s;
        res.en = rt.en;

        res.l = max(lt.l, rt.l);
        res.prl = lt.prl;
        res.sfl = rt.sfl;

        if (lt.en == rt.s) {

            // substring crossing the boundary
            res.l = max(res.l, lt.sfl + rt.prl);

            // Entire left segment has same character
            if (lt.prl == lt.len) {
                res.prl = lt.len + rt.prl;
            }

            // Entire right segment has same character
            if (rt.prl == rt.len) {
                res.sfl = lt.sfl + rt.len;
            }
        }

        return res;
    }

    void build(string &s, int id, int l, int h) {

        if (l == h) {
            segm[id] = Node(1, 1, 1, 1, s[l], s[l]);
            return;
        }

        int md = (l + h) / 2;

        build(s, id * 2 + 1, l, md);
        build(s, id * 2 + 2, md + 1, h);

        segm[id] = merge(
            segm[id * 2 + 1],
            segm[id * 2 + 2]
        );
    }

    void update(int id, int pos, char c, int l, int h) {

        if (l == h) {
            segm[id] = Node(1, 1, 1, 1, c, c);
            return;
        }

        int md = (l + h) / 2;

        if (pos <= md)
            update(id * 2 + 1, pos, c, l, md);
        else
            update(id * 2 + 2, pos, c, md + 1, h);

        segm[id] = merge(
            segm[id * 2 + 1],
            segm[id * 2 + 2]
        );
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        int n = s.size();

        build(s, 0, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {

            int pos = queryIndices[i];
            char c = queryCharacters[i];

            update(0, pos, c, 0, n - 1);

            ans.push_back(segm[0].l);
        }

        return ans;
    }
};