
����һ���� '('��')' ��Сд��ĸ��ɵ��ַ��� s��

����Ҫ���ַ�����ɾ��������Ŀ�� '(' ���� ')' ������ɾ������λ�õ�����)��ʹ��ʣ�µġ������ַ�������Ч��

�뷵������һ���Ϸ��ַ�����

��Ч�������ַ�����Ӧ���������� ����һ�� Ҫ��

���ַ�����ֻ����Сд��ĸ���ַ���
���Ա�д�� AB��A ���� B�����ַ��������� A �� B ������Ч�������ַ�����
���Ա�д��(A) ���ַ��������� A ��һ����Ч�ġ������ַ�����


ʾ�� 1��

���룺s = "lee(t(c)o)de)"
�����"lee(t(c)o)de"
���ͣ�"lee(t(co)de)", "lee(t(c)ode)" Ҳ��һ�����д𰸡�
ʾ�� 2��

���룺s = "a)b(c)d"
�����"ab(c)d"
ʾ�� 3��

���룺s = "))(("
�����""
���ͣ����ַ���Ҳ����Ч��
ʾ�� 4��

���룺s = "(a(b(c)d)"
�����"a(b(c)d)"

//����˼·�������е����ź����ǵ�������pair<char,int>������ջ��ͬʱ����Ե���Ч���ų�ջ��
//���ʣ�µľ�����Ч�����Լ���������������ʣ�µ�������ԭ�ַ�����ɾ����Ӧ������

class Solution {
public:
	string minRemoveToMakeValid(string s) {
		stack<pair<char, int>>ss;
		for (int i = 0; i<s.size(); i++){
			pair<char, int>t;
			t.first = s[i];
			t.second = i;
			if (!ss.empty()){
				if (ss.top().first == '('&&t.first == ')'){
					ss.pop();
					continue;
				}
				if (t.first == '('){
					ss.push(t);
					continue;
				}
			}
			if (t.first == '(' || t.first == ')'){
				ss.push(t);
			}
		}
		while (!ss.empty()){
			s.erase(s.begin() + ss.top().second);
			ss.pop();
		}
		return s;
	}
};
