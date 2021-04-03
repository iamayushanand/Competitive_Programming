from urllib2 import urlopen
import subprocess
from HTMLParser import HTMLParser
from BeautifulSoup import BeautifulSoup
from sys import argv


Template = 'main.cpp'
class ParseProblem(HTMLParser):
	def __init__(self, folder):
		 HTMLParser.__init__(self)
		 self.folder = folder
		 self.num_tests = 0
		 self.testcase = None
		 self.start_copy = False
                 self.end_line=True

	def handle_starttag(self, tag, attrs):
		if tag=='div':
			if attrs == [('class','input')]:
				self.num_tests+=1
				self.testcase = open("%s/%s%d.in" %(self.folder, "TestCase",self.num_tests),'w+' )
			elif attrs == [('class','output')]:
				self.testcase = open("%s/%s%d.out" % (self.folder,"TestCase",self.num_tests) , 'w+')
		elif tag=='pre':
			if self.testcase != None:
				self.start_copy = True
	def handle_endtag(self,tag):
		if tag == 'br':
			if self.start_copy:
#				self.testcase.write('\n'.encode('utf-8'))
				self.end_line=True
		if tag== 'pre':
			if self.start_copy:
				if not self.end_line:
					self.testcase.write('\n'.encode('utf-8'))
			if self.testcase != None: self.testcase.close()
			self.testcase = None
			self.start_copy = False
	def handle_entityref(self,name):
		if self.start_copy:
			self.testcase.write(self.unescape(('&%s;'% name)).encode('utf-8'))
	def handle_data(self,data):
		if self.start_copy:
			self.testcase.write(data.encode('utf-8'))

def main():
	print "Codeforces problem parser made by Ayush version 1.0"

	
	if(len(argv)<2):
		print "No problem code entered."
		return
	if(len(argv)!=3):
		problem1 = argv[1][0:3]
		problem2 = argv[1][3]
	else:
		problem1 = argv[1]
		problem2 = argv[2]
	subprocess.call(['mkdir','-p',argv[1]+argv[2]])
	

	print "Please wait while the problem is being parsed..."
	if(len(argv)==3):
			data = urlopen("http://www.codeforces.com/contest/"+problem1+"/problem/"+problem2).read()
	else:
		data = urlopen("http://www.codeforces.com/problemset/problem/"+problem1+"/"+problem2).read()
	soup = BeautifulSoup(data)
	title = soup.title.string

	
	
	print "Reading problem "+title+"..."
        

        
        subprocess.call(['cp' ,'-n' , 'main.cpp',argv[1]+argv[2]+'/main.cpp'])
	subprocess.call(['cp','-n','tester.sh',argv[1]+argv[2]+'/tester.sh'])
	subprocess.call(['chmod','+x',argv[1]+argv[2]+'/tester.sh'])

	parser = ParseProblem(argv[1]+argv[2]+'/')
	parser.feed(data.decode('utf-8'))
	print "Job Done"

if __name__ == '__main__':
	main()
