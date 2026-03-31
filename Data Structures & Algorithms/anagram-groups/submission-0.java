class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String,List<String>> hashMap = new HashMap<>();
        List<List<String>> finalAns = new ArrayList<>();
        for (int i = 0 ; i < strs.length ; i++) {
            String sortedString = strs[i];
            char[] charArray = sortedString.toCharArray();
            Arrays.sort(charArray);
            sortedString = new String(charArray);
            hashMap.putIfAbsent(sortedString, new ArrayList<>());
            hashMap.get(sortedString).add(strs[i]);
        }
        for (Map.Entry<String,List<String>> entry:hashMap.entrySet()) {
            finalAns.add(entry.getValue());
        }
        return finalAns;
    }
}
