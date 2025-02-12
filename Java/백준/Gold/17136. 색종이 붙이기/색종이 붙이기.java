import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class Main {

    static int[][] map = new int[10][10];
    static int[] postit = new int[6];
    static int total_1 = 0;
    static int answer = Integer.MAX_VALUE;

    public static boolean checkMap(int cur, int n) {
        int x = cur % 10;
        int y = cur / 10;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int nx = x + j;
                int ny = y + i;
                if (nx < 0 || ny < 0 || nx >= 10 || ny >= 10) return false;
                if (map[ny][nx] == 0) return false;
            }
        }
        return true;
    }

    public static void setMap(int cur, int n, boolean flag) {
        //flag가 true 이면 색종이 덮기(배열을 0으로 바꾸기), flag가 false이면 색종이 다시 떼기(배열 1로 바꾸기)
        int x = cur % 10;
        int y = cur / 10;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                map[y + i][x + j] = flag ? 0 : 1;
            }
        }
    }

    public static int getUsedPostit() {
        int cnt = 0;
        for (int i = 1; i <= 5; i++) {
            cnt += (5 - postit[i]);
        }
        return cnt;
    }

    public static void dfs(int cur) {
        for (int i = 0; i < cur; i++) {
            if (map[i / 10][i % 10] == 1) return;
        }

        for (int n = 5; n >= 1; n--) {
            if (postit[n] > 0 && checkMap(cur, n)) { //postit이 남아있고, postit으로 가릴 수 있으면 붙이고 다른칸 탐색
                // map을 포스팃으로 덮어서 0으로 바꾸기
                postit[n]--; //n*n 포스팃 1개 사용
                setMap(cur, n, true);  // 포스팃으로 덮었으니 0으로 바꾸기
                total_1 -= n * n;
                if (total_1 == 0) {
                    answer = Math.min(answer, getUsedPostit());
//                    continue;
                }

                for (int i = cur + n; i < 100; i++) {
                    dfs(i);
                }
                // 다시 되돌리기
                postit[n]++;
                setMap(cur, n, false);
                total_1 += n * n;
            }
        }
    }

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer sb;

        int first = -1;  //처음으로 1이 등장하는 위치 저장
        //map 정보 입력
        for (int i = 0; i < 10; i++) {
            sb = new StringTokenizer(br.readLine());
            for (int j = 0; j < 10; j++) {
                int num = Integer.parseInt(sb.nextToken());
                if (num == 1) {
                    total_1++;
                    if (first == -1) {
                        first = 10 * i + j;
                    }

                }
                map[i][j] = num;
            }
        }

        //포스트 5개씩 추가
        for (int n = 1; n <= 5; n++) {
            postit[n] = 5;
        }

        if (total_1 == 0) {
            bw.write(0 + "\n");

        } else {

            dfs(first);
            bw.write((answer == Integer.MAX_VALUE ? -1 : answer) + "\n");
        }
        bw.flush();
        bw.close();
        br.close();
    }
}





