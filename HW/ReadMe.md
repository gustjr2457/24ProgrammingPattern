# 202202034 서현석 과제

### VCS란 무엇인가
어떤 파일이 여러번의 수정을 거쳐야하고 각각의 수정 전 상태들도 모두 남기고자 한다면 우리는 보통 파일의 사본을 만들고 파일명 뒤에 _수정, _최종수정등을 붙여가며 기존파일과 구분하곤 합니다. VCS는 이처럼 파일에 변경사항이 생겼을 때 파일의 수정했던 기록(버전)들을 저장할 수 있는 소프트웨어로 만약 사용자가 모든 수정사항마다 저장 명령어를 사용해 파일의 수정 기록을 남겨놓았다면 사용자는 VCS를 이용해 원하는 특정 수정 시점으로 파일을 돌릴 수 있습니다. VCS의 역할은 단순히 파일의 수정사항을 저장해놓고 특정 시점으로 돌려주는것 뿐만 아니라 파일을 실수로 삭제하더라도 삭제된 파일을 복구시킬 수 있고, 여러명이 함께 진행하는 프로젝트가 있을 경우 Github와 같은 원격 저장소를 통해 더 안전하고 효율적으로 작업이 진행될 수 있도록 모든 수정사항들을 프로젝트 참여자들의 명령에 따라 동기화 및 저장하며 수정에 대한 정보 (누가, 언제, 어떤 파일을, 파일의 어떤 부분을 수정했는지)를 제공해줍니다. 또한 단순히 코드가 들어있는 파일뿐만 아니라 이미지, txt 파일등도 가능하기 때문에 개발자는 물론이며 디자이너, 기획자외에도 파일의 수정사항을 남겨야 하는 사람들에게 유용한 소프트웨어입니다.

### DVCS와 VCS의 차이점

일단 DVCS는 Distributed Version Control System (분산형 버전 관리 시스템) 의 약자로 Git이 사용하는 VCS 방식입니다. DVCS는 프로젝트의 전체 파일이 참여자들의 각 컴퓨터와 서버에 분산되어 저장됩니다. 먼저 로컬 저장소(참여자들의 각 컴퓨터 디스크)에 프로젝트파일들을 1차적으로 저장하고 사용자의 명령에 따라 Github, Bitbucket과 같은 원격 저장소(서버 저장소)에도 저장할 수 있습니다. 파일을 서버와 각 참여자들의 컴퓨터에 분산하여 저장할 수 있기 때문에 어느 한쪽에 문제가 생겨 파일이 손상되거나 히스토리가 지워지더라도 다른 쪽에서 받아오면 되기 때문에 쉽게 복구할 수 있습니다. 만약 네트워크 문제로 원격 저장소와 통신이 되지 않는다면 각 참여자들끼리 로컬 저장소내의 파일들을 다양한 방법(이메일 등)으로 주고 받을 수 있어 프로젝트를 계속 진행할 수 있습니다. DVCS에서는 원격 저장소에 저장하는것이 필수가 아닌 선택사항이고 로컬 저장소에 먼저 저장 한 뒤에 명령이 가능하기 때문에 개발자의 실수로 잘못 커밋을 했더라도 원격 저장소로 올리기 전이었다면 다른 개발자들에게 영향을 주기않고 수정 할 수 있습니다. VCS와 DVCS의 차이점은 VCS는 CVCS와 DVCS를 모두 통틀어 말하는 root와 같은 친구이고 DVCS는 VCS의 방식중 하나로 트리에서 부모와 자식 노드같은 그런 관계라고 할 수 있기 때문에 차이점을 찾으라고 하기엔 애매해서 CVCS와 DCVS의 차이점을 나열하겠습니다.
일단 히스토리 저장 위치가 CVCS는 원격 저장소이고 DVCS는 로컬 저장소 및 서버 저장소 라는 차이점이 있습니다.
두번째로, 커밋 순서가 CVCS는 참여자->원격저장소 순으로 이루어지지만 DVCS는 참여자->로컬 저장소->원격 저장소 순으로 이루어집니다.
대표 소프트웨어로는 CVCS는 CVS, Subversion, Perforce가 있고 DVCS는 Git, Mercurial, BitKeeper, Bazaar이 있습니다.

---
### GIT을 이용하여 remote repository를 생성하고 git용 bash 로 local repository랑 연결하는 과정을 스크린샷과 함께 각 명령어의 자세한 설명을 작성하시오. 
![첫번째](https://github.com/gustjr2457/24ProgrammingPattern/assets/127166744/9554a7d8-5bd7-4363-96fb-9adc12c8856c)
#### <br>프로필 사진을 누른 뒤 Repositories를 눌러 들어간 뒤 New를 누른다
![두번째](https://github.com/gustjr2457/24ProgrammingPattern/assets/127166744/100db6b6-8b9f-46e5-b391-3a6dc8e600a2)
#### <br>이름을 작성한 후 Create repository를 누르면 remote repository가 생성된다 (README는 선택사항)
![세번째](https://github.com/gustjr2457/24ProgrammingPattern/assets/127166744/bd9e626f-c2e9-4287-8c1e-c623b9a7f941)
#### 1. change directory로 remote repository와 연결할 위치로 이동한다<br>
#### 2. git config --global user.name, user.email로 사용자의 정보를 입력한다 config는 사용자 정보 설정을 할 때 사용하는 명령어이다.<br>
#### --global은 git 서버 전체의 설정 값을 설정한다. 이 옵션을 사용하지 않으면 현재 이용하고 있는 Git 저장소에 대해서만 설정한다.
#### 3. git init으로 해당 위치에 git 초기화를 해준다.
![Fourth](https://github.com/gustjr2457/24ProgrammingPattern/assets/127166744/cfac86ad-b7a6-4362-aa3d-c878e497d4c6)
#### git remote add origin https://github.com/gustjr2457/24ProgrammingPattern.git 로 local repository와 remote repository를 연결한다. 
#### git remote add 이름 저장소_주소 : 새로운 원격 저장소를 등록한다. -f 옵션과 같이 쓰면, git fetch가 함께 실행된다.

###  .gitignore 사용법과 작성방식 및 내용에 대해서 조사를 해 오시오.
- 사용법
새로운 .gitignore 파일 생성: 프로젝트 루트 디렉토리에 .gitignore 파일을 만듭니다. 만약 이미 .gitignore 파일이 있다면 그 파일을 엽니다.
<br>
원하는 내용 추가: .gitignore 파일에는 Git이 추적하지 않아야 하는 파일 및 디렉토리의 패턴을 추가합니다. 예를 들어, Visual Studio 프로젝트의 경우 Visual Studio에서 생성하는 빌드 결과물, 임시 파일 등을 추가할 수 있습니다.
<br>
패턴 추가 방법: 파일이나 디렉토리 이름을 직접 작성합니다. 예를 들어, bin/ 또는 *.suo. 와일드카드(*)를 사용하여 패턴을 작성할 수 있습니다. 예를 들어, *.log는 확장자가 .log인 모든 파일을 무시합니다.
<br>하위 디렉토리를 지정하기 위해 /를 사용할 수 있습니다. 예를 들어, **/node_modules/는 모든 하위 디렉토리에 있는 node_modules 폴더를 무시합니다.
<br>
주석 추가: 필요에 따라 주석을 추가하여 다른 개발자가 .gitignore 파일을 이해하도록 돕습니다.
<br>
저장 및 커밋: .gitignore 파일을 저장하고 Git 저장소에 커밋합니다. 이제 Git은 .gitignore에 명시된 파일 및 디렉토리를 무시합니다.

- 작성방식
파일 무시: 특정 파일을 무시하려면 해당 파일의 이름을 .gitignore 파일에 적습니다. 예를 들어, example.txt를 무시하려면 example.txt라고 .gitignore 파일에 추가하면 됩니다.
<br>
와일드카드: 와일드카드(*)는 여러 파일을 한 번에 지정하는 데 사용됩니다. 예를 들어, *.log는 모든 확장자가 .log인 파일을 무시합니다. *은 모든 것을 나타냅니다. 따라서 *만 사용하면 모든 파일을 무시합니다.
<br>
디렉토리 무시: 디렉토리를 무시하려면 해당 디렉토리의 이름을 .gitignore 파일에 추가합니다. 예를 들어, logs/는 logs 디렉토리와 그 하위 디렉토리를 모두 무시합니다.
<br>
주석: 주석은 #으로 시작합니다. 주석은 .gitignore 파일 내에서 설명을 추가하는 데 사용됩니다. 주석 뒤의 모든 내용은 Git에 의해 무시됩니다.
<br>
부분 경로 지정: 패턴은 부분 경로를 지정할 수 있습니다. 예를 들어, **/logs/는 모든 하위 디렉토리에 있는 logs 디렉토리를 무시합니다.
<br>
반전 패턴: 느낌표(!)는 반전 패턴을 나타냅니다. 즉, 특정 파일이나 디렉토리를 무시하지 않도록 할 수 있습니다. 예를 들어, !important.log는 important.log 파일을 무시하지 않습니다.
<br>

- .gitignore 내용 조사
*.rsuser, *.suo, *.user, *.userosscache, *.sln.docstates: 사용자별 파일이나 Visual Studio 솔루션 상태 파일 등을 무시합니다.<br>
*.userprefs: MonoDevelop/Xamarin Studio의 사용자 설정 파일을 무시합니다.<br>
mono_crash.*: Mono 개발 환경에서 발생하는 크래시 덤프 파일을 무시합니다.<br>
[Dd]ebug/, [Rr]elease/, x64/, x86/, [Ww][Ii][Nn]32/, [Aa][Rr][Mm]/, [Aa][Rr][Mm]64/, bld/, [Bb]in/, [Oo]bj/, [Ll]og/, [Ll]ogs/: 빌드 결과물과 관련된 디렉토리들을 무시합니다.<br>
.vs/: Visual Studio 설정 디렉토리를 무시합니다.<br>
Generated\ Files/: Visual Studio 2017에서 자동 생성되는 파일을 무시합니다.<br>
[Tt]est[Rr]esult*/, [Bb]uild[Ll]og.*: 테스트 결과 및 빌드 로그 파일을 무시합니다.<br>
*.VisualState.xml, TestResult.xml, nunit-*.xml: NUnit 테스트 결과 파일을 무시합니다.<br>
[Dd]ebugPS/, [Rr]eleasePS/, dlldata.c: ATL 프로젝트의 빌드 결과물 및 ATL 빌드 스크립트 파일을 무시합니다.<br>
BenchmarkDotNet.Artifacts/: BenchmarkDotNet 결과물을 무시합니다.<br>
project.lock.json, project.fragment.lock.json, artifacts/: .NET Core 프로젝트 관련 파일을 무시합니다.<br>
ScaffoldingReadMe.txt: ASP.NET Scaffolding의 README 파일을 무시합니다.<br>
StyleCopReport.xml: StyleCop 리포트 파일을 무시합니다.<br>
*_i.c, *_p.c, *_h.h, *.ilk, *.meta, *.obj, *.iobj, *.pch, *.pdb, *.ipdb, *.pgc, *.pgd, *.rsp, *.sbr, *.tlb, *.tli, *.tlh, *.tmp, *.tmp_proj, *_wpftmp.csproj, *.log, *.tlog, *.vspscc, *.vssscc, .builds, *.pidb, *.svclog, *.scc: Visual Studio에서 생성되는 빌드 및 임시 파일들을 무시합니다.<br>
_Chutzpah*: Chutzpah 테스트 파일들을 무시합니다.<br>
ipch/, *.aps, *.ncb, *.opendb, *.opensdf, *.sdf, *.cachefile, *.VC.db, *.VC.VC.opendb: Visual C++ 관련 캐시 파일들을 무시합니다.<br>
*.psess, *.vsp, *.vspx, *.sap: Visual Studio 프로파일러 파일들을 무시합니다.<br>
*.e2e: Visual Studio 추적 파일들을 무시합니다.<br>
$tf/: TFS 2012 Local Workspace 파일들을 무시합니다.<br>
*.gpState: Guidance Automation Toolkit 상태 파일을 무시합니다.<br>


---
### ReadMe.md 파일에 사용된 Mark Down 표기법 에대해서 헤더/목록(숫자)/순서없는목록(ex>*) / 들여쓰기 / 코드블럭 / 수평선 /링크 / 이미지/ 강조 에 대해 사용 방법을 정리해 오시오

* 헤더

<'h1'> 부터 <'h6'>까지 '#'을 통해 헤더 표현이 가능하다.

* 목록

숫자를 사용한 리스트는 숫자. 으로 사용 가능하다. 숫자 앞에 띄어쓰기를 2번 하면 숫자 앞에 탭으로 띄어쓰기를 하여 하위 목록을 만들 수 있다.<br>
ex)
1. 목록 1
    1. 하위 목록 i
    2. 하위 목록 ii
        1. 더 하위 목록 a
        2. 더 하위 목록 b

* 순서 없는 목록

'-','*','+' 기호를 이용하여 순서 없는 목록을 이용할 수 있다.

- 목록 1
- 목록 2
    - 하위 목록 1
    - 하위 목록 2
        - 더 하위 목록 1
        - 더 하위 목록 2

* 들여쓰기
<'br'> 을 통해 들여쓰기를 할 수 있다.

* 코드블럭
코드 블럭을 만드는 방법은 '`'을 3번 이상 연속으로 입력하는 것이다.
그리고 그 뒤에 코드 종류를 적어주면 해당  스타일에 맞게 하이라이팅 되는 것을 볼 수 있다.
```C++
void main() {
    std::cout << "Hello world" << std::endl;
}
```

* 수평선
수평선은 '-', '*', '_'을 3개 이상 입력하여 추가할 수 있다.

---

* 링크
링크를 붙여넣기 하면 된다!

* 이미지
github에서 issue에 들어가서 new issue를 누른 뒤 이미지를 드래그해서 url을 만든 후 md파일에 붙여넣으면 된다!

* 강조
이텔릭체 표현을 위해서 '*' 혹은 '_'를 표현하고자 하는 곳에 앞뒤로 하나씩 붙여준다.<br>
볼드체 표현을 위해서는 '*' 혹은 '_'를 표현하고자 하는 곳에 앞뒤로 두개씩 붙여준다.<br>
취소선 표현을 위해서는 '~'를 표현하고자 하는 곳에 앞뒤로 붙여준다.
