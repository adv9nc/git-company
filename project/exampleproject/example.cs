namespace BladeLineage
{
    public class BladeLineageInitializer : ModInitializer
    {
        public override void OnInitializeMod()
        {
            try
            {
                base.OnInitializeMod();
                Harmony harmorny = new Harmony("LOR_BladeLineage_MOD");
                MethodInfo method = typeof(BladeLineageInitializer).GetMethod("BookModel_SetXmlInfo");
                harmorny.Patch(typeof(BookModel).GetMethod("SetXmlInfo", AccessTools.all), null, new HarmonyMethod(method), null, null, null);
                BladeLineageInitializer.path = Path.GetDirectoryName(Uri.UnescapeDataString(new UriBuilder(Assembly.GetExecutingAssembly().CodeBase).Path));
                BladeLineageInitializer.language = GlobalGameManager.Instance.CurrentOption.language;
                BladeLineageInitializer.GetArtWorks(new DirectoryInfo(BladeLineageInitializer.path + "/ArtWork"));
                BladeLineageInitializer.AddLocalize();
            }
            catch (Exception ex)
            {
                using (StreamWriter streamWriter = File.AppendText(Application.dataPath + "/Mods/BladeLineageError.txt"))
                {
                    TextWriter textWriter = streamWriter;
                    Exception ex2 = ex;
                    textWriter.WriteLine(((ex2 != null) ? ex2.ToString() : null) + ex.StackTrace);
                }
            }
        }

        public static void BookModel_SetXmlInfo(BookModel __instance,BookXmlInfo ____classInfo, ref List<DiceCardXmlInfo> ____onlyCards)
        {
            if (__instance.BookId.packageId == BladeLineageInitializer.packageId)
            {
                foreach (int id in ____classInfo.EquipEffect.OnlyCard)
                {
                    DiceCardXmlInfo cardItem = ItemXmlDataList.instance.GetCardItem(new LorId(BladeLineageInitializer.packageId, id), false);
                    ____onlyCards.Add(cardItem);
                }
            }
        }

        public static void AddLocalize()
        {
            Dictionary<string, BattleEffectText> dictionary = typeof(BattleEffectTextsXmlList).GetField("_dictionary", AccessTools.all).GetValue(Singleton<BattleEffectTextsXmlList>.Instance) as Dictionary<string, BattleEffectText>;
            System.IO.FileInfo[] files = new DirectoryInfo(BladeLineageInitializer.path + "/Localize/" + BladeLineageInitializer.language + "/EffectTexts").GetFiles();
            for (int i = 0; i < files.Length; i++)
            {
                using (StringReader stringReader = new StringReader(File.ReadAllText(files[i].FullName)))
                {
                    BattleEffectTextRoot battleEffectTextRoot = (BattleEffectTextRoot)new XmlSerializer(typeof(BattleEffectTextRoot)).Deserialize(stringReader);
                    for (int j = 0; j < battleEffectTextRoot.effectTextList.Count; j++)
                    {
                        BattleEffectText battleEffectText = battleEffectTextRoot.effectTextList[j];
                        dictionary.Add(battleEffectText.ID, battleEffectText);
                    }
                }
            }
        }
        
        public static void GetArtWorks(DirectoryInfo dir)
        {
            if (dir.GetDirectories().Length != 0)
            {
                DirectoryInfo[] directories = dir.GetDirectories();
                for (int i = 0; i < directories.Length; i++)
                {
                    BladeLineageInitializer.GetArtWorks(directories[i]);
                }
            }
            foreach (System.IO.FileInfo fileInfo in dir.GetFiles())
            {
                Texture2D texture2D = new Texture2D(2, 2);
                texture2D.LoadImage(File.ReadAllBytes(fileInfo.FullName));
                Sprite value = Sprite.Create(texture2D, new Rect(0f, 0f, (float)texture2D.width, (float)texture2D.height), new Vector2(0f, 0f));
                string fileNameWithoutExtension = Path.GetFileNameWithoutExtension(fileInfo.FullName);
                BladeLineageInitializer.ArtWorks[fileNameWithoutExtension] = value;
            }
        }
        public static string packageId = "BladeLineage";
        public static string path;
        public static string language;
        public static Dictionary<string, Sprite> ArtWorks = new Dictionary<string, Sprite>();  
    }
}
