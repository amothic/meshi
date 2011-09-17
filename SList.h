#ifndef SLIST_H_
#define SLIST_H_

#include <cassert>
#include <cstddef>

// 単方向リスト
template <typename TYPE>
	class SList
{
	public:
		// ノード
		struct Node {
			TYPE value;		// ノードの保持する値
			Node* next;		// 次のノード
		};

	public:
		SList() { m_eol.next = NULL; }
		virtual ~SList() { Clear(); }

		// 先頭ノードを取得
		Node*       GetFirst()       { return m_eol.next; }
		const Node* GetFirst() const { return m_eol.next; }

		// node の次の位置にノードを挿入
		Node* Insert(Node* node, const TYPE& value) {
			assert(node != NULL);
			Node* next = new Node();
			next->value = value;
			next->next = node->next;
			return node->next = next;
		}

		// 先頭位置に値を挿入
		Node* Unshift(const TYPE& value) {
			return Insert(&m_eol, value);
		}

		// 全削除
		void Clear() {
			Node* next;
			for (Node* node = m_eol.next; node != NULL; node = next) {
				next = node->next;
				delete node;
			}
			m_eol.next = NULL;
		}

	private:
		// リストの端(end of list)を表すノード
		// next に先頭ノードが入れられる
		Node m_eol;
};

#endif // #ifndef SLIST_H_

