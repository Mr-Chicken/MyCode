int i;double d; const string *ps; char *pc; void *pv;

(a)pv = (void*)ps;			pv = std::static_cast<void*>(std::const_cast<string*>(ps))
(b)i = int(*pc);			i = std::static_cast<int>(*pc)
(c)pv = &d;					pv = std::static_cast<void*>(&d)
(d)pc = (char*) pv;			pc = std::static_cast<char*>(pc);			